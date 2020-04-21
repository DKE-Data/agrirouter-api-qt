//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "ResponsePoll.h"

#include "Settings.h"
#include "Utils.h"
#include "AgrirouterMessage.h"
#include "CCIAgrirouter/ICommunicationInterface.h"
#include "CCIAgrirouter/Globals.h"

namespace CCIAgrirouter
{

ResponsePoll::ResponsePoll(ICommunicationInterface *communicationInterface, QObject *parent)
    : QObject(parent)
    , m_communicationInterface(communicationInterface)
{

}

ResponsePoll::~ResponsePoll()
{

}

void ResponsePoll::pollForResponse()
{
    QString commands = Settings::getInstance().getCommands();
    if (commands.isEmpty())
    {
        qWarning() << "Commands URL is missing";
        return;
    }

    QNetworkRequest request;
    request.setSslConfiguration(m_communicationInterface->getSslConfiguration());
    request.setUrl(commands);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QString acceptHeader = "Accept";
    QString acceptHeaderValue = "application/json";
    request.setRawHeader(acceptHeader.toUtf8(), acceptHeaderValue.toUtf8());

    NetworkReply reply = m_communicationInterface->sendGetRequest(request);
    QString response = handleReceivedReply(reply);
    if (!response.isEmpty())
    {
        Q_EMIT receivedResponse(response);
    }
    else
    {
        Q_EMIT receivedNoResponse(reply.statusCode);
    }
}

QString ResponsePoll::handleReceivedReply(const NetworkReply &reply)
{
    QString data;

    if (reply.errorCode)
    {
        m_error = "HTTP ERROR: " + reply.errorString;
        Utils::printErrorMessageFromReply(reply.data);
    }
    else if (reply.statusCode == HTTPStatusCode_OK)
    {
        data = reply.data;
        if (data == "[]")
        {
            data.clear();
        }
    }
    else
    {
        m_error = "Failed getting response from Agrirouter. StatusCode: " + QString::number(reply.statusCode)
                + " " + reply.reasonPhrase;
        qWarning() << m_error;
    }

    return data;
}

QString ResponsePoll::getError()
{
    return m_error;
}

}
