//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "MessageSender.h"
#include "Settings.h"
#include "CCIAgrirouter/ICommunicationInterface.h"
#include "CCIAgrirouter/Globals.h"
#include "Utils.h"
#include "AgrirouterMessage.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

namespace CCIAgrirouter
{

MessageSender::MessageSender(ICommunicationInterface *communicationInterface, QObject *parent)
    : QObject(parent)
    , m_communicationInterface(communicationInterface)
{

}

MessageSender::~MessageSender()
{

}

Reply MessageSender::sendMessage(const QString &message)
{
    if (message.isEmpty())
    {
        return Reply();
    }

    QString measures = Settings::getInstance().getMeasures();
    if (measures.isEmpty())
    {
        qWarning() << "Measures URL is missing";
        return Reply();
    }

    QNetworkRequest request;
    request.setSslConfiguration(m_communicationInterface->getSslConfiguration());
    request.setUrl(measures);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QString acceptHeader = "Accept";
    QString acceptHeaderValue = "application/json";
    request.setRawHeader(acceptHeader.toUtf8(), acceptHeaderValue.toUtf8());

    NetworkReply reply = m_communicationInterface->sendMessage(request, message.toUtf8());
    return handleReceivedReply(reply);
}

QString MessageSender::getReplyMessage(const QString &data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    // check validity of the document
    if(doc.isNull() || (!doc.isObject()) || (doc.object().isEmpty()))
    {
        return QString();
    }

    QJsonObject responseObject = doc.object();

    QJsonValue msgValue = responseObject.value("msg");
    if (!msgValue.isNull())
    {
        return msgValue.toString();
    }

    return QString();
}

Reply MessageSender::parseReply(const NetworkReply &receivedReply)
{
    Reply reply;
    reply.statusCode = receivedReply.statusCode;
    reply.message = getReplyMessage(receivedReply.data);
    return reply;
}

Reply MessageSender::handleReceivedReply(const NetworkReply &receivedReply)
{
    // No connection
    if (receivedReply.statusCode == HTTPStatusCode_NOTSET)
    {
        return Reply();
    }

    if (receivedReply.errorCode)
    {
        m_error = "HTTP error: " + receivedReply.errorString;
        qDebug() << m_error;
        Utils::printErrorMessageFromReply(receivedReply.data);
    }
    else if (receivedReply.statusCode != HTTPStatusCode_OK)
    {
        m_error = "Failed sending message to Agrirouter. StatusCode: " + receivedReply.statusCode
                + receivedReply.reasonPhrase;
        qWarning() << m_error;
    }

    return parseReply(receivedReply);
}

}
