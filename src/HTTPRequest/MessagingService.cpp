//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "MessagingService.h"
#include "MessageSender.h"
#include "ResponsePollLoop.h"
#include "MessageConverter.h"
#include "CCIAgrirouter/ICommunicationInterface.h"
#include "CCIAgrirouter/Globals.h"
#include <QEventLoop>

namespace CCIAgrirouter
{

MessagingService::MessagingService(ICommunicationInterface *communicationInterface, QObject *parent)
    : QObject(parent)
    , m_communicationInterface(communicationInterface)
{

}

MessagingService::~MessagingService()
{

}

Reply MessagingService::send(std::shared_ptr<AgrirouterMessage> message_inout)
{
    if (message_inout == nullptr)
    {
        return Reply();
    }

    MessageSender sender(m_communicationInterface);
    message_inout->setRequestTimestamp();
    return sender.sendMessage(message_inout->getRequestMessage().toJson());
}

QList<ResponseMessage> MessagingService::poll(qint32 maxTrys)
{
    QTimer timer;
    QEventLoop eventLoop;
    (void)connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);

    ResponsePollLoop pollLoop(m_communicationInterface, maxTrys, this);
    (void)connect(&pollLoop, &ResponsePollLoop::receivedNoResponse, &eventLoop, &QEventLoop::quit);
    (void)connect(&pollLoop, &ResponsePollLoop::receivedResponse, &eventLoop, &QEventLoop::quit);

    // Timeout for all trys, NOT for one single try
    qint32 timeoutAllTrys = Settings::getInstance().getTimeoutMsecs() * maxTrys;
    timer.start(timeoutAllTrys);

    pollLoop.start();
    if (pollLoop.isRunning())
    {
        eventLoop.exec();
    }

    if (!timer.isActive())
    {
        qDebug() << "Response poll timed out";
        return QList<ResponseMessage>();
    }

    timer.stop();
    disconnect(&eventLoop);

    QString responseString = pollLoop.getResponse();
    if (responseString.isEmpty())
    {
        return QList<ResponseMessage>();
    }

    return MessageConverter::decodeResponseString(responseString);
}

}
