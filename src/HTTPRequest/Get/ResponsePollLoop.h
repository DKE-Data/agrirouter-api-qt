//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef RESPONSEPOLLLOOP_5BB6C54505B44177890D257C36429D2A
#define RESPONSEPOLLLOOP_5BB6C54505B44177890D257C36429D2A

#include <QObject>

namespace CCIAgrirouter
{

class ICommunicationInterface;
class ResponsePoll;

class ResponsePollLoop : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ResponsePollLoop)
public:
    ResponsePollLoop(ICommunicationInterface* communicationInterface, QObject *parent = nullptr);
    ResponsePollLoop(ICommunicationInterface* communicationInterface, qint32 pollTryCount, QObject *parent = nullptr);
    ~ResponsePollLoop();

    void setpollTryCount(qint32 pollTryCount);
    void start();

    bool isRunning();
    QString getResponse();

Q_SIGNALS:
    void receivedNoResponse();
    void receivedResponse();

public Q_SLOTS:
    void onReceivedNoResponse(qint32 statusCode);
    void onReceivedResponse(QString response);

private:
    ICommunicationInterface* const m_communicationInterface;
    ResponsePoll* const m_responsePoll;
    qint32 m_currentTry = 0;
    qint32 m_pollTryCount = 10;
    QString m_response;
    bool m_isRunning = false;
};

}

#endif//RESPONSEPOLLLOOP_5BB6C54505B44177890D257C36429D2A
