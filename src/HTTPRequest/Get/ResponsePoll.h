//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef RESPONSEPOLL_08536E8F239F4DC7BD3A377482752E13
#define RESPONSEPOLL_08536E8F239F4DC7BD3A377482752E13

#include <QObject>
#include <QString>

namespace CCIAgrirouter
{

class ICommunicationInterface;
struct NetworkReply;
struct Response;

class ResponsePoll : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ResponsePoll)
public:
    ResponsePoll(ICommunicationInterface* communicationInterface, QObject *parent = nullptr);
    ~ResponsePoll();

    void pollForResponse();
    QString sendGetCapabiltiesRequest(const QString &deviceId);

    Response tryGettingNewMessages();

    QString getError();

Q_SIGNALS:
    void receivedResponse(QString response);
    void receivedNoResponse(qint32 statusCode);

private:
    QString handleReceivedReply(const NetworkReply &reply);
    QList<QString> getMessagesFromResponse(const QString &data);

    ICommunicationInterface* const m_communicationInterface;
    QString m_error;

};

}

#endif // __ResponsePoll_H__08536e8f239f4dc7bd3a377482752e13
