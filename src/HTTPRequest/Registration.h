//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef REGISTRATION_E363A8A381714D448AEA2D35D195EB99
#define REGISTRATION_E363A8A381714D448AEA2D35D195EB99

#include <QObject>

class QNetworkReply;

namespace CCIAgrirouter
{

class ICommunicationInterface;
struct NetworkReply;

class Registration : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Registration)
public:
    Registration(ICommunicationInterface* communicationInterface, QObject *parent = nullptr);
    ~Registration();

    bool postOnboard(const QString &registrationCode, const QString &certificateFileName = "certificate");

private:
    bool handleReceivedOnboardReply(const NetworkReply &reply, const QString &certificateFileName);

    ICommunicationInterface* const m_communicationInterface;
};

}

#endif//REGISTRATION_E363A8A381714D448AEA2D35D195EB99
