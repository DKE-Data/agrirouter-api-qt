//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "ResponsePollLoop.h"
#include <QTimer>
#include <QEventLoop>
#include "ResponsePoll.h"
#include "CCIAgrirouter/ICommunicationInterface.h"
#include "CCIAgrirouter/Globals.h"
#include "Settings.h"

namespace CCIAgrirouter
{

ResponsePollLoop::ResponsePollLoop(ICommunicationInterface *communicationInterface, QObject *parent)
    : QObject(parent)
    , m_communicationInterface(communicationInterface)
    , m_responsePoll(new ResponsePoll(communicationInterface, this))
    , m_isRunning(false)
{
    (void)connect(m_responsePoll, &ResponsePoll::receivedResponse, this, &ResponsePollLoop::onReceivedResponse);
    (void)connect(m_responsePoll, &ResponsePoll::receivedNoResponse, this, &ResponsePollLoop::onReceivedNoResponse);
}

ResponsePollLoop::ResponsePollLoop(ICommunicationInterface *communicationInterface, qint32 pollTryCount, QObject *parent)
    : ResponsePollLoop(communicationInterface, parent)
{
    m_pollTryCount = pollTryCount;
}

ResponsePollLoop::~ResponsePollLoop()
{
    disconnect(this);
}

void ResponsePollLoop::setpollTryCount(qint32 pollTryCount)
{
    m_pollTryCount = pollTryCount;
}

void ResponsePollLoop::start()
{
    m_isRunning = true;
    m_responsePoll->pollForResponse();
}

bool ResponsePollLoop::isRunning()
{
    return m_isRunning;
}

void ResponsePollLoop::onReceivedNoResponse(qint32 statusCode)
{   
    if (((++m_currentTry) < m_pollTryCount) && (statusCode == HTTPStatusCode_OK))
    {
        QTimer::singleShot(Settings::getInstance().getTimeoutMsecs(), this, &ResponsePollLoop::start);
        return;
    }

    m_isRunning = false;
    Q_EMIT receivedNoResponse();
}

void ResponsePollLoop::onReceivedResponse(QString response)
{
    m_response = response;
    m_isRunning = false;
    Q_EMIT receivedResponse();
}

QString ResponsePollLoop::getResponse()
{
    return m_response;
}

}
