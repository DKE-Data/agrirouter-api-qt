//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef HTTPSENDER_C9A80326995046999290D20A2BAEAFFC
#define HTTPSENDER_C9A80326995046999290D20A2BAEAFFC

#include <QObject>
#include <QAuthenticator>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "HTTPConnection.h"

namespace CCIAgrirouter
{
    struct NetworkReply;
}

class HTTPSender : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(HTTPSender)
public:
    HTTPSender(HTTPConnection *httpConnection);
    ~HTTPSender();

    void post(const QNetworkRequest &request, const QByteArray &data);
    void get(const QNetworkRequest &request);

    QString getErrorMessage();

    CCIAgrirouter::NetworkReply getReply() const;
    bool isRunning();

Q_SIGNALS:
    void errorReceivingReply();
    void receivedReply();

public Q_SLOTS:
    void onFinished(QNetworkReply *reply);
    void onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);

private:
    HTTPConnection* const m_httpConnection;
    HTTPRequestBundle m_requestBundle;
    QString m_error;
    CCIAgrirouter::NetworkReply m_reply;
    bool m_isRunning = false;

};


#endif//HTTPSENDER_C9A80326995046999290D20A2BAEAFFC
