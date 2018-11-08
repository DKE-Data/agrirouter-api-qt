//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "CCIAgrirouter/AgrirouterClient.h"
#include <google/protobuf/util/time_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/timestamp.pb.h>
#include "AgrirouterClientPrivate.h"
#include "AgrirouterMessageUtils.h"
#include "MessageConverter.h"
#include "Settings.h"
#include "MessageQueue.h"

//Protobuf includes
#include "messaging/request/payload/account/endpoints.pb.h"
#include "messaging/request/payload/endpoint/subscription.pb.h"
#include "messaging/request/payload/feed/feed-requests.pb.h"

namespace CCIAgrirouter
{

AgrirouterClient::AgrirouterClient(ICommunicationInterface* communicationInterface, QObject *parent)
    : QObject(parent)
    , m_d(new AgrirouterClientPrivate(communicationInterface, this))
{
    (void)connect(m_d, &AgrirouterClientPrivate::sendFileResult, this, &AgrirouterClient::onSendFileResult);
}

AgrirouterClient::~AgrirouterClient()
{
    disconnect(this);
}

void AgrirouterClient::setSettingsParameters(const SettingsParameters &params)
{
    Settings::getInstance().setParameters(params);
    m_d->initializeCommunicationInterface();
}

void AgrirouterClient::establishConnection()
{
    QByteArray passPhrase = Utils::decodeBase64(Settings::getInstance().getSslPassphrase());
    m_d->establishConnection(passPhrase);
}

void AgrirouterClient::closeConnection()
{
    m_d->closeConnection();
}

bool AgrirouterClient::isConnected()
{
    return m_d->isConnected();
}

void AgrirouterClient::applicationReady()
{
    m_d->applicationReady();
}

bool AgrirouterClient::hasCertificate()
{
    return m_d->certificateExists();
}

bool AgrirouterClient::hasCapabilities()
{
    return (m_d->getCapabilities()->capabilities_size() > 0);
}

void AgrirouterClient::addCapability(const QString &technicalMessageType, const MessageTypeDirection &direction)
{
    m_d->addCapability(technicalMessageType, direction);
}

void AgrirouterClient::registerEndpoint(const QString &registrationCode)
{
    bool success = m_d->onboard(registrationCode);
    Q_EMIT registerEndpointResult(success);
}

void AgrirouterClient::sendFile(const QString &filepath, FileType filetype, const QStringList &recipients)
{
    if (filepath.isEmpty())
    {
        Q_EMIT sendFileResult(filepath, filetype, false);
        return;
    }

    QString technicalMessageType;
    switch (filetype)
    {
    case FileType_TASKDATA_ZIP:
        technicalMessageType = TechnicalMessageType::TASKDATA_ZIP;
        break;

    case FileType_SHAPE_ZIP:
    case FileType_JPEG:
    case FileType_PNG:
    case FileType_NOTSET:
    default:
        Q_EMIT sendFileResult(filepath, filetype, false);
        return;
    }

    // DEBUG: Log the recipients
    if (!recipients.isEmpty())
    {
        qDebug() << "Sending message to recipients:" << recipients;
    }
    else
    {
        qDebug() << "Publishing message";
    }

    QByteArray filedata = Utils::readFile(filepath);

    // The full message must not exceed 1mb encoded. So files larger than 500kb will be sent in chunks
    const qint32 CHUNK_SIZE_LIMIT = 500000;

    // Create ChunkMessage object if needed and split the filedata into chunks
    if (filedata.size() >= CHUNK_SIZE_LIMIT)
    {
        std::shared_ptr<ChunkMessage> chunkMessage = std::make_shared<ChunkMessage>();
        chunkMessage->contextId = Utils::createUuid();
        chunkMessage->totalSize = filedata.size();

        qint32 index = 0;

        // Split filedata into chunks <= 500kb
        while (filedata.size() > CHUNK_SIZE_LIMIT)
        {
            chunkMessage->data.insert(index++, filedata.left(CHUNK_SIZE_LIMIT));
            filedata.remove(0, CHUNK_SIZE_LIMIT);
        }

        // Also add the last chunk to the list that may be smaller than 500kb
        if (filedata.size() > 0)
        {
            chunkMessage->data.insert(index, filedata);
        }

        chunkMessage->numberOfChunks = chunkMessage->data.size();

        m_filesToSend.insert(chunkMessage->contextId, filepath);
        sendChunkMessage(chunkMessage, recipients, technicalMessageType);
    }
    // Normal message without chunks
    else
    {
        QString messageId = Utils::createUuid();
        agrirouter::request::RequestEnvelope_Mode mode = recipients.isEmpty()
                ? agrirouter::request::RequestEnvelope_Mode_PUBLISH
                : agrirouter::request::RequestEnvelope_Mode_DIRECT;

        Request request;
        request.envelope = AgrirouterMessageUtils::createRequestHeader(messageId
                                                                       , m_d->getNextSeqNo()
                                                                       , technicalMessageType
                                                                       , mode
                                                                       , recipients);

        QByteArray data = Utils::encodeBase64(filedata);
        request.payloadWrapper.mutable_details()->set_value(data.constData(), static_cast<int>(data.length()));

        m_filesToSend.insert(messageId, filepath);
        m_d->addRequestToMessageQueue(request);
        m_d->tryToSendUnfinishedRequests(false);
    }
}

void AgrirouterClient::sendChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage, const QStringList &recipients, const QString &technicalMessageType)
{
    agrirouter::request::RequestEnvelope_Mode mode = recipients.isEmpty()
            ? agrirouter::request::RequestEnvelope_Mode_PUBLISH
            : agrirouter::request::RequestEnvelope_Mode_DIRECT;

    // Create messageIDs for every chunk message
    // This needs to be done before the requests are added to the send queue
    for (qint32 i = 0; i < chunkMessage->data.size(); ++i)
    {
        chunkMessage->messageIDs.insert(i, Utils::createUuid());
    }

    m_d->addChunkMessageToSend(chunkMessage);

    // Create a request for every chunk and send it
    for (qint32 i = 0; i < chunkMessage->data.size(); ++i)
    {
        Request request;
        request.envelope = AgrirouterMessageUtils::createRequestHeader(chunkMessage->messageIDs.at(i)
                                                                       , m_d->getNextSeqNo()
                                                                       , technicalMessageType
                                                                       , mode
                                                                       , recipients);

        agrirouter::commons::ChunkComponent *chunkComponent = request.envelope.mutable_chunk_info();
        chunkComponent->set_context_id(chunkMessage->contextId.toStdString());
        chunkComponent->set_current(i + 1); // i + 1 because current starts at 1
        chunkComponent->set_total(chunkMessage->numberOfChunks);
        chunkComponent->set_total_size(chunkMessage->totalSize);

        const QByteArray &rawData = chunkMessage->data.value(i);
        if (rawData.isEmpty())
        {
            qWarning() << "The chunk data are incomplete or corrupted";
            return;
        }

        QByteArray data = Utils::encodeBase64(rawData);
        request.payloadWrapper.mutable_details()->set_value(data.constData(), static_cast<int>(data.length()));

        // Add all messages to the send queue before sending
        m_d->addRequestToMessageQueue(request);
    }

    // Send all messages
    m_d->tryToSendUnfinishedRequests(false);
}

void AgrirouterClient::sendCapabilities()
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                m_d->getNextSeqNo(),
                                                TechnicalMessageType::CAPABILITIES,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    request.setPayload(m_d->getCapabilities());

    m_d->addRequestToMessageQueue(request);
    m_d->tryToSendUnfinishedRequests(false);
}

void AgrirouterClient::sendSubscription(QStringList technicalMessageTypes)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                m_d->getNextSeqNo(),
                                                TechnicalMessageType::SUBSCRIPTION,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    agrirouter::request::payload::endpoint::Subscription subscription;
    for (QString messageType : technicalMessageTypes)
    {
        subscription.add_technical_message_types()->set_technical_message_type(messageType.toStdString());
    }

    request.setPayload(&subscription);

    m_d->addRequestToMessageQueue(request);
    m_d->tryToSendUnfinishedRequests(false);
}

void AgrirouterClient::sendDeviceDescription(efdi::ISO11783_TaskData &deviceDescription)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                m_d->getNextSeqNo(),
                                                TechnicalMessageType::DEVICE_DESCRIPTION,
                                                agrirouter::request::RequestEnvelope_Mode_PUBLISH);

    request.envelope.set_team_set_context_id(Settings::getInstance().getTeamSetContextId().toStdString());
    request.setPayload(&deviceDescription);

    m_d->addRequestToMessageQueue(request);
    m_d->tryToSendUnfinishedRequests(false);
}

void AgrirouterClient::requestEndpointList()
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                m_d->getNextSeqNo(),
                                                TechnicalMessageType::LIST_ENDPOINTS_UNFILTERED,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    request.payloadWrapper.mutable_details()->set_value(QString(".agrirouter.request.payload.account.ListEndpointsQuery").toStdString());

    m_d->addRequestToMessageQueue(request);
    m_d->tryToSendUnfinishedRequests(false);
}

void AgrirouterClient::requestEndpointList(const QString &messageType, MessageTypeDirection direction)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                m_d->getNextSeqNo(),
                                                TechnicalMessageType::LIST_ENDPOINTS,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    agrirouter::request::payload::account::ListEndpointsQuery listEndpointsQuery;
    listEndpointsQuery.set_technical_message_type(messageType.toStdString());

    switch (direction)
    {
    case MessageTypeDirection_SEND:
        listEndpointsQuery.set_direction(agrirouter::request::payload::account::ListEndpointsQuery_Direction_SEND);
        break;

    case MessageTypeDirection_RECEIVE:
        listEndpointsQuery.set_direction(agrirouter::request::payload::account::ListEndpointsQuery_Direction_RECEIVE);
        break;

    case MessageTypeDirection_SEND_RECEIVE:
        listEndpointsQuery.set_direction(agrirouter::request::payload::account::ListEndpointsQuery_Direction_SEND_RECEIVE);
        break;

    case MessageTypeDirection_NOTSET:
    default:
        break;
    }

    request.setPayload(&listEndpointsQuery);
    m_d->addRequestToMessageQueue(request);
    m_d->tryToSendUnfinishedRequests(false);
}

QString AgrirouterClient::getExternalId()
{
    return Settings::getInstance().getExternalId();
}

void AgrirouterClient::deleteCertificateFiles(const QString &externalId)
{
    Utils::deleteCertificateFiles(externalId);
}

void AgrirouterClient::resetToDefault()
{
    Utils::deleteCertificateFiles();
    Settings::getInstance().clearSettings();
    m_d->setNewTeamSetContextId();
}

QString AgrirouterClient::getFilePathForMessageId(const QString &messageId)
{
    if (!m_filesToSend.contains(messageId))
    {
        qDebug() << "File path for sent file not found";
        return QString();
    }

    return m_filesToSend.value(messageId);
}

void AgrirouterClient::onSendFileResult(const QString &messageId, FileType fileType, bool success)
{
    QString filePath = getFilePathForMessageId(messageId);
    if (!filePath.isEmpty())
    {
        m_filesToSend.remove(messageId);
    }

    Q_EMIT sendFileResult(filePath, fileType, success);
}

void AgrirouterClient::checkForNewMessages(QStringList senders, bool forceCheckForChunks)
{
    if ((!m_d->isSending()) || forceCheckForChunks)
    {
        m_d->requestMessageHeadersFromSenders(senders, forceCheckForChunks);
    }
}

void AgrirouterClient::checkForNewMessages(quint32 periodInMinutes, bool forceCheckForChunks)
{
    if ((!m_d->isSending()) || forceCheckForChunks)
    {
        m_d->requestMessageHeadersFromPeriod(periodInMinutes, forceCheckForChunks);
    }
}

}
