//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "HTTPSender.h"
#include <CCIAgrirouter/Globals.h>
#include <CCIAgrirouter/ICommunicationInterface.h>

HTTPSender::HTTPSender(HTTPConnection *httpConnection)
    : QObject(httpConnection)
    , m_httpConnection(httpConnection)
{
    (void)connect(m_httpConnection->networkManager(), &QNetworkAccessManager::finished, this, &HTTPSender::onFinished);
    (void)connect(m_httpConnection->networkManager(), &QNetworkAccessManager::authenticationRequired, this, &HTTPSender::onAuthenticationRequired);
}

HTTPSender::~HTTPSender()
{
    disconnect(this);
}

void HTTPSender::onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    QString clientId = m_httpConnection->getUaaClientId();
    QString secret = m_httpConnection->getUaaSecret();
    if (clientId.isEmpty() || secret.isEmpty())
    {
        qCritical() << "Error: SSL-Authentication failed. Please set client-ID and password before connecting";
        return;
    }

    authenticator->setUser(clientId);
    authenticator->setPassword(secret);
}

void HTTPSender::post(const QNetworkRequest &request, const QByteArray &data)
{
    m_isRunning = true;
    m_requestBundle = HTTPRequestBundle(request, HTTPOperation_POST, data);
    m_httpConnection->networkManager()->post(request, data);
}

void HTTPSender::get(const QNetworkRequest &request)
{
    m_requestBundle = HTTPRequestBundle(request, HTTPOperation_GET);
    m_httpConnection->networkManager()->get(request);
}

QString HTTPSender::getErrorMessage()
{
    return m_error;
}

CCIAgrirouter::NetworkReply HTTPSender::getReply() const
{
    return m_reply;
}

bool HTTPSender::isRunning()
{
    return m_isRunning;
}

void HTTPSender::onFinished(QNetworkReply* reply)
{
    if (!reply)
    {
        m_error = "No reply received";
        m_isRunning = false;
        Q_EMIT errorReceivingReply();
        return;
    }

    QVariant possibleRedirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    QUrl possibleRedirectUrl = possibleRedirectionTarget.toUrl();

    // Redirect handling
    if (!possibleRedirectUrl.isEmpty())
    {
        qDebug() << "Redirected to: " << possibleRedirectUrl.toString();

        //Set the new URL
        m_requestBundle.request.setUrl(possibleRedirectUrl);

        switch(m_requestBundle.operation)
        {
            case HTTPOperation_POST:
                m_httpConnection->networkManager()->post(m_requestBundle.request, m_requestBundle.data);
                break;

            case HTTPOperation_GET:
                m_httpConnection->networkManager()->get(m_requestBundle.request);
                break;

            case HTTPOperation_NOTSET:
            default:
            {
                m_error = "Wrong operation";
                m_isRunning = false;
                Q_EMIT errorReceivingReply();
                break;
            }
        }

        // In case of url redirect do not emit a signal
        // onFinished() will be called again
        return;
    }

    qint32 statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if ((statusCode != CCIAgrirouter::HTTPStatusCode_OK) && (statusCode != CCIAgrirouter::HTTPStatusCode_OK_DATA_CREATED))
    {
        qDebug() << "Server replied HTTP " << QString::number(statusCode)
                                     << " " << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    }

    m_requestBundle = HTTPRequestBundle();
    m_reply = CCIAgrirouter::NetworkReply(reply);
    m_isRunning = false;
    Q_EMIT receivedReply();

    // From QNetworkAccessManager documentation:
    // "Note: Do not delete the object in the slot connected to this signal. Use deleteLater()."
    reply->deleteLater();
    return;
}
