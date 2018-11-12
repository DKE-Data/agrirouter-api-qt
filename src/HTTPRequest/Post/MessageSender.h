//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef MESSAGESENDER_5F02A2F1325F431F924FC9EC6648DF77
#define MESSAGESENDER_5F02A2F1325F431F924FC9EC6648DF77

#include <QObject>

class QNetworkReply;

namespace CCIAgrirouter
{

class ICommunicationInterface;
struct NetworkReply;
struct Reply;

class MessageSender : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MessageSender)
public:
    MessageSender(ICommunicationInterface* communicationInterface, QObject *parent = nullptr);
    ~MessageSender();

    Reply sendMessage(const QString &message);

private:
    Reply handleReceivedReply(const NetworkReply &receivedReply);
    Reply parseReply(const NetworkReply &receivedReply);
    QString getReplyMessage(const QString &data);

    ICommunicationInterface* const m_communicationInterface;
    QString m_error;

};

}

#endif//MESSAGESENDER_5F02A2F1325F431F924FC9EC6648DF77
