//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "AgrirouterClientPrivate.h"
#include "CCIAgrirouter/AgrirouterClient.h"
#include "CCIAgrirouter/ICommunicationInterface.h"
#include "AgrirouterMessageUtils.h"
#include "Registration.h"
#include "MessagingService.h"
#include "MessageSender.h"
#include "MessageConverter.h"
#include "Settings.h"
#include <QDirIterator>

//Protobuf includes
#include "messaging/request/payload/feed/feed-requests.pb.h"
#include "messaging/response/payload/account/endpoints.pb.h"

namespace CCIAgrirouter
{

AgrirouterClientPrivate::AgrirouterClientPrivate(ICommunicationInterface* communicationInterface, AgrirouterClient* parent)
    : QObject(parent)
    , m_communicationInterface(communicationInterface)
    // For multi-user management the certificateFileName will be set user-specific.
    // In the current version there is no need to store multiple certificate files,
    // so they are just named "certificate"
    , m_certificateName("certificate")
    , m_q(parent)
{
    (void)connect(&m_responsePollTimer, &QTimer::timeout, this, &AgrirouterClientPrivate::onResponsePollTimeout);
}

AgrirouterClientPrivate::~AgrirouterClientPrivate()
{
    disconnect(this);

    if (m_capabilities)
    {
        delete m_capabilities;
        m_capabilities = nullptr;
    }
}

bool AgrirouterClientPrivate::certificateExists()
{
    const Settings& settings = Settings::getInstance();
    QString certificateFilePath = settings.getDataDir() + QDir::separator() + settings.getExternalId();
    bool certificateFound = false;

    if (settings.getCertificateType() == CertificateType::PEM)
    {
        certificateFound = (Utils::fileExists(certificateFilePath + ".pem")
                 && Utils::fileExists(certificateFilePath + ".key"));
    }
    else if (settings.getCertificateType() == CertificateType::P12)
    {
        certificateFound = Utils::fileExists(certificateFilePath + ".p12");
    }

    return certificateFound;
}

bool AgrirouterClientPrivate::establishConnection(const QByteArray &passPhrase)
{
    if (!communicationInterfaceAvailable())
    {
        return false;
    }

    if (certificateExists())
    {
        if (m_communicationInterface->establishConnection(passPhrase))
        {
            Q_EMIT m_q->connected();
        }
    }
    else
    {
        qDebug() << "No SSL Certificate found. Please register first.";
    }

    return false;
}

void AgrirouterClientPrivate::closeConnection()
{
    m_communicationInterface->closeConnection();
    Q_EMIT m_q->disconnected();
}

bool AgrirouterClientPrivate::isConnected()
{
    return m_communicationInterface->isConnected();
}

void AgrirouterClientPrivate::applicationReady()
{
    // Check if there are unfinished chunks
    // If yes, read the tmp files into the chunk message queue
    readTmpChunkFiles();
}

bool AgrirouterClientPrivate::onboard(const QString &registrationCode)
{
    if (!communicationInterfaceAvailable())
    {
        return false;
    }

    Registration registration(m_communicationInterface, this);
    if (registration.postOnboard(registrationCode, m_certificateName))
    {
        settingsChanged();
        initializeCommunicationInterface();
        return true;
    }

    return false;
}

void AgrirouterClientPrivate::settingsChanged()
{
    const Settings &settings = Settings::getInstance();

    SettingsParameters params;
    params.sslPassphrase = settings.getSslPassphrase();
    params.sensorAlternateId = settings.getSensorAlternateId();
    params.externalId = settings.getExternalId();
    params.capabilityAlternateId = settings.getCapabilityAlternateId();
    params.deviceAlternateId = settings.getDeviceAlternateId();
    params.measures = settings.getMeasures();
    params.commands = settings.getCommands();
    params.iotServicesHost = settings.getIotServicesHost();
    params.certificateType = settings.getCertificateType();
    params.teamSetContextId = settings.getTeamSetContextId();

    Q_EMIT m_q->settingsChanged(params);
}

void AgrirouterClientPrivate::addCapability(const QString &technicalMessageType, const MessageTypeDirection &direction)
{
    agrirouter::request::payload::endpoint::CapabilitySpecification* capabilitySpecification = getCapabilities();
    if (capabilitySpecification == nullptr)
    {
        qDebug() << "Protobuf pointer error";
        return;
    }

    agrirouter::request::payload::endpoint::CapabilitySpecification_Capability* capability = capabilitySpecification->add_capabilities();
    if (capability == nullptr)
    {
        qDebug() << "Protobuf pointer error";
        return;
    }

    capability->set_technical_message_type(technicalMessageType.toStdString());

    switch (direction)
    {
    case MessageTypeDirection_SEND:
        capability->set_direction(agrirouter::request::payload::endpoint::CapabilitySpecification_Direction_SEND);
        break;

    case MessageTypeDirection_RECEIVE:
        capability->set_direction(agrirouter::request::payload::endpoint::CapabilitySpecification_Direction_RECEIVE);
        break;

    case MessageTypeDirection_SEND_RECEIVE:
        capability->set_direction(agrirouter::request::payload::endpoint::CapabilitySpecification_Direction_SEND_RECEIVE);
        break;

    case MessageTypeDirection_NOTSET:
    default:
        qWarning() << "Could not set capability" << technicalMessageType << "Reason: Invalid direction";
        return;
    }
}

void AgrirouterClientPrivate::requestMessageByMessageId(const QString &messageId)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                getNextSeqNo(),
                                                TechnicalMessageType::FEED_MESSAGE_QUERY,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    agrirouter::feed::request::MessageQuery messageQuery;
    messageQuery.add_message_ids(messageId.toStdString());
    request.setPayload(&messageQuery);

    qDebug() << "Requesting message" << messageId;
    addRequestToMessageQueue(request);
    sendUnfinishedRequests();
}

void AgrirouterClientPrivate::confirmMessageFeed(const QStringList &messageIDs)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                getNextSeqNo(),
                                                TechnicalMessageType::FEED_CONFIRM,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    agrirouter::feed::request::MessageConfirm messageConfirm;

    for (QString messageId : messageIDs)
    {
        qDebug() << "Confirming message" << messageId;
        messageConfirm.add_message_ids(messageId.toStdString());
    }

    request.setPayload(&messageConfirm);
    addRequestToMessageQueue(request);
    sendUnfinishedRequests();
}

void AgrirouterClientPrivate::deleteMessageFeed(const QString &messageId)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                getNextSeqNo(),
                                                TechnicalMessageType::FEED_DELETE,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    agrirouter::feed::request::MessageDelete messageDelete;
    messageDelete.add_message_ids(messageId.toStdString());
    request.setPayload(&messageDelete);

    qDebug() << "Deleting message" << messageId;
    addRequestToMessageQueue(request);
    sendUnfinishedRequests();
}

void AgrirouterClientPrivate::requestMessageHeadersFromSenders(const QStringList &senders, bool forceCheckForChunks)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                getNextSeqNo(),
                                                TechnicalMessageType::FEED_HEADER_QUERY,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    agrirouter::feed::request::MessageQuery headerQuery;
    for (QString sender : senders)
    {
        headerQuery.add_message_ids(sender.toStdString());
    }

    request.setPayload(&headerQuery);

    addRequestToMessageQueue(request);
    tryToSendUnfinishedRequests(forceCheckForChunks);
}

void AgrirouterClientPrivate::requestMessageHeadersFromPeriod(quint32 periodInMinutes, bool forceCheckForChunks)
{
    Request request;
    request.envelope = AgrirouterMessageUtils::createRequestHeader(Utils::createUuid(),
                                                getNextSeqNo(),
                                                TechnicalMessageType::FEED_HEADER_QUERY,
                                                agrirouter::request::RequestEnvelope_Mode_DIRECT);

    qint64 now = (QDateTime::currentMSecsSinceEpoch() / 1000);

    // If period is 0, check for the full time period (4 weeks)
    if ((periodInMinutes == 0) || (periodInMinutes > MAX_POLL_TIME_PERIOD))
    {
        periodInMinutes = MAX_POLL_TIME_PERIOD;
    }

    agrirouter::feed::request::MessageQuery headerQuery;
    headerQuery.mutable_validity_period()->mutable_sentfrom()->set_seconds(now - (periodInMinutes * 60));
    headerQuery.mutable_validity_period()->mutable_sentfrom()->set_nanos(1000000);
    headerQuery.mutable_validity_period()->mutable_sentto()->set_seconds(now);
    headerQuery.mutable_validity_period()->mutable_sentto()->set_nanos(1000000);

    request.setPayload(&headerQuery);

    addRequestToMessageQueue(request);
    tryToSendUnfinishedRequests(forceCheckForChunks);
}

void AgrirouterClientPrivate::addRequestToMessageQueue(const Request &request)
{
    std::shared_ptr<AgrirouterMessage> message(new AgrirouterMessage(request));
    m_messageQueue.addMessage(message);
}

void AgrirouterClientPrivate::tryToSendUnfinishedRequests(bool forceSend)
{
    if ((!m_sending) || forceSend)
    {
        sendUnfinishedRequests();
    }
}

void AgrirouterClientPrivate::sendUnfinishedRequests()
{
    if ((!communicationInterfaceAvailable()) || (!m_communicationInterface->isConnected()))
    {
        return;
    }

    MessagingService messagingService(m_communicationInterface);

    quint32 loopCount = 0;
    m_sending = true;
    while (m_messageQueue.hasUnsentRequests() && (++loopCount < 50))
    {
        std::shared_ptr<AgrirouterMessage> message = m_messageQueue.getNextUnsentMessage();
        if (message == nullptr)
        {
            m_messageQueue.removeMessage(message);
            continue;
        }

        QString messageType = message->getMessageType();

        // If the current message is a header request
        // Clear the message queue from all other header requests
        if (messageType == TechnicalMessageType::FEED_HEADER_QUERY)
        {
            m_messageQueue.clearPendingHeaderRequests();
            m_messageQueue.addMessage(message);
        }
        // Log which file is being sent
        else if (messageType == TechnicalMessageType::TASKDATA_ZIP)
        {
            // Check for chunk info
            Request request = message->getRequest();
            agrirouter::commons::ChunkComponent* chunkInfo = request.envelope.mutable_chunk_info();
            if (!chunkInfo->context_id().empty())
            {
                qDebug() << "Sending file" << messageType << "( Chunk"
                                             << chunkInfo->current() << "of"
                                             << chunkInfo->total() << ")";
            }
            else
            {
                qDebug() << "Sending file" << message->getMessageType();
            }
        }

        // Send message
        Reply reply = messagingService.send(message);

        // Check if message was sent successfully
        if (reply.statusCode == HTTPStatusCode_OK)
        {
            message->setSent(true);
            continue;
        }
        // This occurs when the endpoint is deleted from the agrirouter account
        // so the registration is not valid anymore
        else if (reply.statusCode == HTTPStatusCode_BAD_REQUEST)
        {
            m_sending = false;
            m_messageQueue.clear();
            Q_EMIT m_q->receivedBadRequest();
            closeConnection();
            return;
        }
        // This occurs when there is no internet connection
        else if (reply.statusCode == HTTPStatusCode_NOTSET)
        {
            m_sending = false;

            // Remove header requests
            m_messageQueue.clearPendingHeaderRequests();
            Q_EMIT m_q->noInternetConnection();
            return;
        }

        qDebug() << "Reply: HTTP " << reply.statusCode << reply.message;

        message->incrementSendCount();
        if (message->getSendCount() >= 3)
        {
            Request request = message->getRequest();
            m_messageQueue.removeMessage(message);

            QString technicalMessageType = QString::fromStdString(request.envelope.technical_message_type());
            QString messageId = QString::fromStdString(request.envelope.application_message_id());

            // Inform the app about failed message sending
            if (technicalMessageType == TechnicalMessageType::TASKDATA_ZIP)
            {
                Q_EMIT sendFileResult(messageId, FileType_TASKDATA_ZIP, false);
            }
            else if (technicalMessageType == TechnicalMessageType::CAPABILITIES)
            {
                Q_EMIT m_q->sendCapabilitiesResult(false);
            }
            else if (technicalMessageType == TechnicalMessageType::SUBSCRIPTION)
            {
                Q_EMIT m_q->sendSubscriptionResult(false);
            }
        }
    }

    startPollForResponses();
}

void AgrirouterClientPrivate::readTmpChunkFiles()
{
    QDir tmpDir = Utils::getTmpChunkDir();
    if (!tmpDir.exists())
    {
        return;
    }

    QList<QFileInfo> chunkDataFiles;

    QDirIterator dirIt(tmpDir, QDirIterator::NoIteratorFlags);
    while (dirIt.hasNext())
    {
        dirIt.next();
        const QFileInfo &fileInfo = dirIt.fileInfo();
        if (fileInfo.isFile())
        {
            if (fileInfo.suffix() != TMP_FILE_SUFFIX)
            {
                continue;
            }

            // Check if the filename is a valid UUID
            // In this case the file contains the chunk information
            if (!QUuid(fileInfo.baseName()).isNull())
            {
                QFile chunkInfoFile(dirIt.filePath());
                if (!chunkInfoFile.exists())
                {
                    continue;
                }

                if (chunkInfoFile.open(QIODevice::ReadOnly))
                {
                    QByteArray data = QByteArray::fromBase64(chunkInfoFile.readAll());
                    chunkInfoFile.close();

                    agrirouter::commons::ChunkComponent chunkInfo;
                    if (chunkInfo.ParseFromString(data.toStdString()))
                    {
                        std::shared_ptr<ChunkMessage> chunkMessage(new ChunkMessage());
                        chunkMessage->contextId = QString::fromStdString(chunkInfo.context_id());
                        chunkMessage->numberOfChunks = chunkInfo.total();
                        chunkMessage->totalSize = chunkInfo.total_size();

                        m_messageQueue.addReceivedChunkMessage(chunkMessage);
                    }
                    else
                    {
                        qDebug() << "Cannot parse chunk info. File may be corrupted";
                    }
                }
                else
                {
                    qDebug() << "Cannot read file" << chunkInfoFile.fileName();
                }
            }
            else
            {
                chunkDataFiles.append(fileInfo);
            }
        }
    }

    // Read chunk data tmp files
    for (QFileInfo chunkDataFile : chunkDataFiles)
    {
        if (!chunkDataFile.exists())
        {
            continue;
        }

        QStringList splittedFileName = chunkDataFile.baseName().split("_");
        if (splittedFileName.size() != 2)
        {
            qDebug() << "Invalid filename" << chunkDataFile.fileName();
            continue;
        }

        QString currentChunkNumberString = splittedFileName.at(0);
        QString chunkContextId = splittedFileName.at(1);
        bool isInt = false;
        qint64 currentChunkNumber = currentChunkNumberString.toInt(&isInt);
        if (!isInt)
        {
            qDebug() << "Invalid filename" << chunkDataFile.fileName();
            continue;
        }

        std::shared_ptr<ChunkMessage> chunkMessage = m_messageQueue.getReceivedChunkMessageById(chunkContextId);
        if (chunkMessage == nullptr)
        {
            qDebug() << "No chunk info found for the existing chunk data";
            continue;
        }

        QFile file(chunkDataFile.absoluteFilePath());
        if (!file.exists())
        {
            continue;
        }

        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray chunkData = file.readAll();
            chunkMessage->data.insert(static_cast<int>(currentChunkNumber) - 1, QByteArray::fromBase64(chunkData));
            file.close();
        }
        else
        {
            qWarning() << "Cannot read file" << chunkDataFile.fileName();
        }
    }
}

void AgrirouterClientPrivate::writeTmpChunkInfoFile(std::shared_ptr<ChunkMessage> chunkMessage)
{
    QDir tmpDir = Utils::getTmpChunkDir();
    if (!tmpDir.exists())
    {
        return;
    }

    QFile tmpFile(tmpDir.absolutePath() + QDir::separator() + chunkMessage->contextId + "." + TMP_FILE_SUFFIX);

    // Overwrite the file if it already exists
    if (tmpFile.exists())
    {
        if (!tmpFile.remove())
        {
            qWarning() << "Cannot delete existing file" << tmpFile.fileName();
            return;
        }
    }

    if (tmpFile.open(QIODevice::WriteOnly))
    {
        agrirouter::commons::ChunkComponent chunkInfo;
        chunkInfo.set_context_id(chunkMessage->contextId.toStdString());
        chunkInfo.set_total(chunkMessage->numberOfChunks);
        chunkInfo.set_total_size(chunkMessage->totalSize);

        tmpFile.write(QByteArray::fromStdString(chunkInfo.SerializeAsString()).toBase64());
        tmpFile.close();
    }
    else
    {
        qWarning() << "Cannot create chunk tmp file";
    }
}

void AgrirouterClientPrivate::writeTmpChunkDataFile(qint64 currentChunk, const QString &chunkContextId, const QByteArray &data)
{
    QDir tmpDir = Utils::getTmpChunkDir();
    if (!tmpDir.exists())
    {
        return;
    }

    QFile chunkDataFile(tmpDir.absolutePath() + QDir::separator() + QString::number(currentChunk) + "_" + chunkContextId + "." + TMP_FILE_SUFFIX);

    // Overwrite the file if it already exists
    if (chunkDataFile.exists())
    {
        if (!chunkDataFile.remove())
        {
            qWarning() << "Cannot delete existing file" << chunkDataFile.fileName();
            return;
        }
    }

    if (chunkDataFile.open(QIODevice::WriteOnly))
    {
        chunkDataFile.write(data.toBase64());
        chunkDataFile.close();
    }
    else
    {
        qWarning() << "Cannot create chunk tmp file";
    }
}

void AgrirouterClientPrivate::removeTmpChunkFiles(const QString &contextId)
{
    QDir tmpDir = Utils::getTmpChunkDir();
    if (!tmpDir.exists())
    {
        return;
    }

    QDirIterator dirIt(tmpDir, QDirIterator::NoIteratorFlags);
    while (dirIt.hasNext())
    {
        dirIt.next();
        if (dirIt.fileInfo().isFile())
        {
            if (dirIt.fileInfo().suffix() != TMP_FILE_SUFFIX)
            {
                continue;
            }

            if (dirIt.fileName().contains(contextId))
            {
                if (!QFile(dirIt.filePath()).remove())
                {
                    qWarning() << "Cannot delete chunk tmp file" << dirIt.fileInfo().fileName();
                }
            }
        }
    }
}

void AgrirouterClientPrivate::startPollForResponses()
{
    if (!m_responsePollTimer.isActive() && m_messageQueue.hasPendingMessages())
    {
        m_responsePollTimer.start(500);
    }
}

void AgrirouterClientPrivate::onResponsePollTimeout()
{
    QList<Response> responses = pollForResponses();
    if (responses.isEmpty())
    {
        Q_EMIT m_q->receivedNoResponse();
    }

    // Update all messages that didn't get a response
    // Even if responses were received for other messages
    m_messageQueue.checkedForResponses();

    if (!m_messageQueue.hasPendingMessages())
    {
        m_sending = false;
        m_responsePollTimer.stop();
    }
}

bool AgrirouterClientPrivate::isSending() const
{
    return m_sending;
}

bool AgrirouterClientPrivate::handleReceivedResponse(const Response &response)
{
    if (response.isEmpty())
    {
        return false;
    }

    QString messageId = QString::fromStdString(response.envelope.application_message_id());
    std::shared_ptr<AgrirouterMessage> message(m_messageQueue.getMessageById(messageId));
    if (message == nullptr)
    {
        qDebug() << "No request found for the received response";
        return false;
    }

    Request request = message->getRequest();
    google::protobuf::Any payload = response.payloadWrapper.details();

    // Check response code for errors
    switch (response.envelope.response_code())
    {
    case AgrirouterResponseCode_OK:
    case AgrirouterResponseCode_OK_DATA_CREATED:
    case AgrirouterResponseCode_OK_NO_CONTENT:
    {
        // No errors. Continue
        break;
    }
    case AgrirouterResponseCode_ERROR_VALIDATION_FAILED:
    {
        // Validation failed
        qWarning() << "Validation failed";

        QString chunkContextId;
        if (request.envelope.has_chunk_info())
        {
            chunkContextId = QString::fromStdString(request.envelope.chunk_info().context_id());
        }

        handleMessagesPayload(payload, chunkContextId);
        return false;
    }
    case AgrirouterResponseCode_ERROR_MESSAGE_TOO_LARGE:
    {
        // Request too large
        qWarning() << "Request is too large. Message needs to be sent in chunks";
        message->setSent(false);
        return false;
    }
    case AgrirouterResponseCode_ERROR_SERVER_OVERLOAD:
    {
        // Server overload
        qWarning() << "Server overload. Try again later";
        message->setSent(false);
        return false;
    }
    case AgrirouterResponseCode_NOTSET:
    default:
    {
        qWarning() << "Missing information in response envelope";
        message->setSent(false);
        return false;
    }
    }

    switch (response.envelope.type())
    {
    case agrirouter::response::ResponseEnvelope::MESSAGES:
    {
        m_messageQueue.removeMessage(message);
        handleMessagesPayload(payload);
        return true;
    }
    case agrirouter::response::ResponseEnvelope::ACK:
    {
        m_messageQueue.removeMessage(message);

        agrirouter::commons::ChunkComponent chunkComponent = request.envelope.chunk_info();
        QString chunkContextId = QString::fromStdString(chunkComponent.context_id());
        if (!chunkContextId.isEmpty())
        {
            // Return here if there are more chunk ACKs to come
            if (!m_messageQueue.sendingChunkedFileFinished(chunkContextId))
            {
                return true;
            }

            // Chunked files are stored in combination with their chunk context ID instead of the message ID
            messageId = chunkContextId;

            // Remove chunk from chunksToSend list
            std::shared_ptr<ChunkMessage> chunkMessage = m_messageQueue.getSentChunkMessageById(chunkContextId);
            if (chunkMessage != nullptr)
            {
                m_messageQueue.removeSentChunkMessage(chunkMessage);
            }
        }

        QString sentMsgType = QString::fromStdString(request.envelope.technical_message_type());
        if (sentMsgType == TechnicalMessageType::TASKDATA_ZIP)
        {
            Q_EMIT sendFileResult(messageId, FileType_TASKDATA_ZIP, true);
        }
        else if (sentMsgType == TechnicalMessageType::CAPABILITIES)
        {
            Q_EMIT m_q->sendCapabilitiesResult(true);
        }
        else if (sentMsgType == TechnicalMessageType::SUBSCRIPTION)
        {
            Q_EMIT m_q->sendSubscriptionResult(true);
        }

        return true;
    }
    case agrirouter::response::ResponseEnvelope::ACK_WITH_MESSAGES:
    {
        m_messageQueue.removeMessage(message);
        handleMessagesPayload(payload);
        return true;
    }
    case agrirouter::response::ResponseEnvelope::ACK_WITH_FAILURE:
    {
        handleMessagesPayload(payload);
        return false;
    }
    case agrirouter::response::ResponseEnvelope::ACK_FOR_FEED_HEADER_LIST:
    {
        m_messageQueue.clearPendingHeaderRequests();
        return handleFeedHeaderListPayload(payload);
    }
    case agrirouter::response::ResponseEnvelope::ACK_FOR_FEED_MESSAGE:
    {
        m_messageQueue.removeMessage(message);

        // Send message confirmation for every received valid message
        QStringList messageIDsToConfirm = handleFeedMessagePayload(payload);
        if (messageIDsToConfirm.isEmpty())
        {
            return false;
        }

        confirmMessageFeed(messageIDsToConfirm);
        return true;
    }
    case agrirouter::response::ResponseEnvelope::ACK_FOR_FEED_FAILED_MESSAGE:
    {
        m_messageQueue.removeMessage(message);
        return handleFeedFailedMessagePayload(payload);
    }
    case agrirouter::response::ResponseEnvelope::ENDPOINTS_LISTING:
    {
        m_messageQueue.removeMessage(message);
        return handleEndpointsListingPayload(payload);
    }
    case agrirouter::response::ResponseEnvelope::CLOUD_REGISTRATIONS:
    {
        //return handleCloudRegistrationsPayload(payload);
        return false;
    }
    case agrirouter::response::ResponseEnvelope_ResponseBodyType_ResponseEnvelope_ResponseBodyType_INT_MIN_SENTINEL_DO_NOT_USE_:
    case agrirouter::response::ResponseEnvelope_ResponseBodyType_ResponseEnvelope_ResponseBodyType_INT_MAX_SENTINEL_DO_NOT_USE_:
    default:
    {
        break;
    }
    }

    return false;
}

bool AgrirouterClientPrivate::handleMessagesPayload(const google::protobuf::Any &payload, const QString &chunkContextId)
{
    agrirouter::commons::Messages messages;
    if (!payload.UnpackTo(&messages))
    {
        qWarning() << "Cannot parse messages. Response type and payload mismatch";
        return false;
    }

    for (const agrirouter::commons::Message &msg : messages.messages())
    {
        QString messageCode = QString::fromStdString(msg.message_code());
        QString messageString = QString::fromStdString(msg.message());

        //TODO
        // Specific agrirouter warning/error message handling can be done here

        // Message confirmed
        if (messageCode == MessageCode::VAL_000206)
        {
            if (m_receivingChunks)
            {
                m_receivingChunks = false;
                m_q->checkForNewMessages(1, true);
            }
        }
        else if (messageCode == MessageCode::NO_CAPABILITIES_CHANGE)
        {
            Q_EMIT m_q->sendCapabilitiesResult(true);
        }
        else if (messageCode == MessageCode::NO_SUBSCRIPTION_CHANGE)
        {
            Q_EMIT m_q->sendSubscriptionResult(true);
        }
        else if (messageCode == MessageCode::VAL_000007)
        {
            Q_EMIT m_q->sendCapabilitiesResult(false);
        }

        Q_EMIT m_q->receivedServerMessage(messageCode, messageString, chunkContextId);
    }

    //AgrirouterMessageUtils::printMessages(&messages);
    return true;
}

bool AgrirouterClientPrivate::handleFeedHeaderListPayload(const google::protobuf::Any &payload)
{
    agrirouter::feed::response::HeaderQueryResponse headerQueryResponse;
    if (!payload.UnpackTo(&headerQueryResponse))
    {
        qWarning() << "Cannot parse header list feed. Response type and payload mismatch";
        return false;
    }

    for (agrirouter::feed::response::HeaderQueryResponse_Feed feed : headerQueryResponse.feed())
    {
        for (agrirouter::feed::response::HeaderQueryResponse_Header header : feed.headers())
        {
            QString msgType = QString::fromStdString(header.technical_message_type());
            if ((msgType == TechnicalMessageType::TASKDATA_ZIP)
                    || (msgType == TechnicalMessageType::SHAPE_ZIP))
            {
                Q_EMIT m_q->checkForNewMessagesResult(true);
                requestMessageByMessageId(QString::fromStdString(header.message_id()));

                // Hotfix: Just handle one message at once
                // There is a bug in handling more messages at the same time
                return true;
            }
        }
    }

    Q_EMIT m_q->checkForNewMessagesResult(false);
    return true;
}

QStringList AgrirouterClientPrivate::handleFeedMessagePayload(const google::protobuf::Any &payload)
{
    agrirouter::feed::response::MessageQueryResponse messageQueryResponse;
    if (!payload.UnpackTo(&messageQueryResponse))
    {
        qWarning() << "Cannot parse message feed. Response type and payload mismatch";
        return QStringList();
    }

    QStringList messageIDsToConfirm;
    for (agrirouter::feed::response::MessageQueryResponse_FeedMessage message : messageQueryResponse.messages())
    {
        QByteArray filedata;
        const agrirouter::commons::ChunkComponent &chunkInfo = message.header().chunk_context();
        QString chunkContextId = QString::fromStdString(chunkInfo.context_id());

        // Chunk message
        if (!chunkContextId.isEmpty())
        {
            std::shared_ptr<ChunkMessage> chunkMessage = m_messageQueue.getReceivedChunkMessageById(chunkContextId);

            // Create chunkMessage if it doesn't exist yet
            if (chunkMessage == nullptr)
            {
                chunkMessage = std::make_shared<ChunkMessage>();
                chunkMessage->contextId = chunkContextId;
                chunkMessage->numberOfChunks = chunkInfo.total();
                chunkMessage->totalSize = chunkInfo.total_size();

                m_messageQueue.addReceivedChunkMessage(chunkMessage);
                writeTmpChunkInfoFile(chunkMessage);
            }

            qDebug() << "Received a chunk message ( Chunk" << chunkInfo.current() << "of" << chunkInfo.total() << ")";

            QByteArray currentChunkFiledata = QByteArray::fromBase64(QByteArray::fromStdString(message.content().value()));

            qint64 index = chunkInfo.current() - 1;

            // If there already are data with the same index, overwrite them
            if (!chunkMessage->data.value(index).isEmpty())
            {
                chunkMessage->data.remove(index);
            }

            chunkMessage->data.insert(index, currentChunkFiledata);

            writeTmpChunkDataFile(chunkInfo.current(), chunkContextId, currentChunkFiledata);

            // Chunk is not complete
            if (chunkMessage->data.size() < chunkMessage->numberOfChunks)
            {
                m_receivingChunks = true;
                messageIDsToConfirm.append(QString::fromStdString(message.header().message_id()));
                continue;
            }
            // Chunk is complete
            else
            {
                // Build the full filedata from all chunks
                for (qint32 i = 0; i < chunkMessage->numberOfChunks; ++i)
                {
                    const QByteArray &currentChunkData = chunkMessage->data.value(i);
                    if (!currentChunkData.isEmpty())
                    {
                        filedata.append(currentChunkData);
                    }
                }

                m_messageQueue.removeReceivedChunkMessage(chunkMessage);
                removeTmpChunkFiles(chunkMessage->contextId);
            }
        }
        // Normal message without chunks
        else
        {
            filedata = QByteArray::fromBase64(QByteArray::fromStdString(message.content().value()));
        }

        if (filedata.isEmpty())
        {
            continue;
        }

        messageIDsToConfirm.append(QString::fromStdString(message.header().message_id()));

        // Inform the app that a file is received
        QString msgType = QString::fromStdString(message.header().technical_message_type());
        if (msgType == TechnicalMessageType::TASKDATA_ZIP)
        {
            Q_EMIT m_q->receivedFile(filedata, FileType_TASKDATA_ZIP);
        }
        else if (msgType == TechnicalMessageType::SHAPE_ZIP)
        {
            Q_EMIT m_q->receivedFile(filedata, FileType_SHAPE_ZIP);
        }
    }

    return messageIDsToConfirm;
}

bool AgrirouterClientPrivate::handleFeedFailedMessagePayload(const google::protobuf::Any &payload)
{
    agrirouter::feed::response::FailedMessageQueryResponse failedMessageQueryResponse;
    if (!payload.UnpackTo(&failedMessageQueryResponse))
    {
        qWarning() << "Cannot parse failed message feed. Response type and payload mismatch";
        return false;
    }

    qint32 messagesInQueue = failedMessageQueryResponse.querymetrics().total_messages_in_query();
    if (messagesInQueue > 0)
    {
        qDebug() << QString::fromStdString(failedMessageQueryResponse.Utf8DebugString());
        qDebug() << "Failed messages in queue: " << QString::number(messagesInQueue);

        for (agrirouter::commons::Message reason : failedMessageQueryResponse.reasons())
        {
            qDebug() << "[" << QString::fromStdString(reason.message_code()) << "] " << QString::fromStdString(reason.message());
        }
    }

    return true;
}

bool AgrirouterClientPrivate::handleEndpointsListingPayload(const google::protobuf::Any &payload)
{
    agrirouter::response::payload::account::ListEndpointsResponse listEndpointsResponse;
    if (!payload.UnpackTo(&listEndpointsResponse))
    {
        qWarning() << "Cannot parse endpoint list. Response type and payload mismatch";
        return false;
    }

    QMap<QString, QString> endpoints;
    for (agrirouter::response::payload::account::ListEndpointsResponse_Endpoint endpoint : listEndpointsResponse.endpoints())
    {
        QString id = QString::fromStdString(endpoint.endpoint_id());
        QString name = QString::fromStdString(endpoint.endpoint_name());
        endpoints.insert(id, name);
    }

    Q_EMIT m_q->receivedEndpointList(endpoints);
    return true;
}

QList<Response> AgrirouterClientPrivate::pollForResponses()
{
    MessagingService messagingService(m_communicationInterface);
    QList<ResponseMessage> responseMessages = messagingService.poll(Settings::getInstance().getPollTryCount());

    QList<Response> responses;
    for (ResponseMessage responseMsg : responseMessages)
    {
        responses.append(MessageConverter::decodeResponse(responseMsg.m_message));
    }

    for (Response response : responses)
    {
        m_messageQueue.addResponse(response);
        handleReceivedResponse(response);
    }

    return responses;
}

void AgrirouterClientPrivate::setNewTeamSetContextId()
{
    Settings::getInstance().setTeamSetContextId(Utils::createUuid());
}

void AgrirouterClientPrivate::initializeCommunicationInterface()
{
    if (m_communicationInterface->getCommunicationType() == CommunicationType_NOTSET)
    {
        qCritical() << "Error: Communication interface cannot be set. No communication type found.";
        return;
    }

    const Settings &settings = Settings::getInstance();

    QString host = settings.getIotServicesHost();
    // Remove "https://" prefix
    QString urlPrefix = "https://";
    if (host.startsWith(urlPrefix))
    {
        host.remove(0, urlPrefix.length());
    }

    m_communicationInterface->setCertificateFilePath(settings.getDataDir());
    m_communicationInterface->setCertificateFileName(settings.getExternalId());
    m_communicationInterface->setHost(host);
    m_communicationInterface->setPort(settings.getIotServicesPort());
    m_communicationInterface->setUaaClientId(settings.getMaiOauthClientId());
    m_communicationInterface->setUaaSecret(settings.getMaiOauthClientSecret());

    return;
}

qint32 AgrirouterClientPrivate::getNextSeqNo()
{
    // Overflow check
    if ((++m_seqNo) >= INT32_MAX)
    {
        m_seqNo = 1;
    }

    return m_seqNo;
}

bool AgrirouterClientPrivate::communicationInterfaceAvailable()
{
    if (!m_communicationInterface)
    {
        qCritical() << "No communication interface found. Please set the communication interface first.";
        return false;
    }

    return true;
}

agrirouter::request::payload::endpoint::CapabilitySpecification* AgrirouterClientPrivate::getCapabilities()
{
    if (m_capabilities == nullptr)
    {
        m_capabilities = new agrirouter::request::payload::endpoint::CapabilitySpecification();

    }

    const Settings &settings = Settings::getInstance();
    m_capabilities->set_app_certification_id(settings.getApplicationId().toStdString());
    m_capabilities->set_app_certification_version_id(settings.getCertificationVersionId().toStdString());

    return m_capabilities;
}

void AgrirouterClientPrivate::addChunkMessageToSend(std::shared_ptr<ChunkMessage> chunkMessage)
{
    m_messageQueue.addChunkMessageToSend(chunkMessage);
}

}
