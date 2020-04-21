//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef MESSAGINGSERVICE_55E7DFF3842841B5A32FEA478D9C96A2
#define MESSAGINGSERVICE_55E7DFF3842841B5A32FEA478D9C96A2

#include <QObject>
#include <QTimer>
#include "AgrirouterMessage.h"

namespace CCIAgrirouter
{

class ICommunicationInterface;

class MessagingService : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MessagingService)
public:
    MessagingService(ICommunicationInterface* communicationInterface, QObject *parent = nullptr);
    ~MessagingService();

    Reply send(std::shared_ptr<AgrirouterMessage> message_inout);
    QList<ResponseMessage> poll(qint32 maxTrys);

private:
    ICommunicationInterface* const m_communicationInterface;
    QTimer m_timer;
};

}

#endif//MESSAGINGSERVICE_55E7DFF3842841B5A32FEA478D9C96A2
