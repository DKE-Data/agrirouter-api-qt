//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "HTTPConnection.h"
#include "HTTPSender.h"
#include <QTimer>
#include <QEventLoop>

HTTPConnection::HTTPConnection(QObject *parent)
    : QObject(parent)
{
    setCommunicationType(CCIAgrirouter::CommunicationType_HTTP);
}

HTTPConnection::HTTPConnection(const QString &host
                               , quint16 port
                               , const QString &certificateFileName
                               , const QString &certificateFilePath
                               , QObject *parent)
    : HTTPConnection(parent)
{
    m_certificateFilePath = certificateFilePath;
    m_certificateFileName = certificateFileName;
    m_host = host;
    m_port = port;
}

HTTPConnection::~HTTPConnection()
{

}

bool HTTPConnection::establishConnection(const QByteArray &passPhrase)
{   
    if (m_certificateFilePath.isEmpty() || m_certificateFileName.isEmpty()
            || m_host.isEmpty() || m_port == 0)
    {
        qWarning() << "Error: Could not establish connection. Required information are missing";
        return false;
    }

    // This is needed to be able to connect right after registering
    m_networkManager.clearAccessCache();

    QString pemFile = m_certificateFilePath + QDir::separator() + m_certificateFileName + ".pem";
    QString keyFile = m_certificateFilePath + QDir::separator() + m_certificateFileName + ".key";

    m_sslSocket.setLocalCertificate(pemFile);
    m_sslSocket.setPrivateKey(keyFile, QSsl::Rsa, QSsl::Pem, passPhrase);

    return connectToHost();
}

bool HTTPConnection::connectToHost()
{
    m_sslSocket.connectToHostEncrypted(m_host, m_port);
    qDebug() << "Connecting to host " << m_host << ":" << QString::number(m_port);
    if (!m_sslSocket.waitForEncrypted(TIMEOUT_MSECS))
    {
        m_sslSocket.close();
        qWarning() << "Could not establish SSL connection: " << m_sslSocket.errorString();
        return retryConnect();
    }

    qDebug() << "Connected";
    return true;
}

bool HTTPConnection::retryConnect()
{
    // Allow m_MAX_RECONNECTS reconnect trys
    if ((++m_reconnectCounter) > MAX_RECONNECTS)
    {
        qCritical() << "Reached max number of reconnects (" << MAX_RECONNECTS << "). Stop trying to connect.";
        m_reconnectCounter = 0;
        return false;
    }

    qDebug() << "Retry connecting";
    return connectToHost();
}

void HTTPConnection::closeConnection()
{
    m_sslSocket.close();
    qDebug() << "Disconnected";
}

bool HTTPConnection::isConnected()
{
    return m_sslSocket.isOpen();
}

QSslConfiguration HTTPConnection::getSslConfiguration()
{
    return m_sslSocket.sslConfiguration();
}

QNetworkAccessManager* HTTPConnection::networkManager()
{
    return &m_networkManager;
}

CCIAgrirouter::NetworkReply HTTPConnection::sendMessage(const QNetworkRequest &request)
{
    return sendMessage(request, QByteArray(0));
}

CCIAgrirouter::NetworkReply HTTPConnection::sendMessage(const QNetworkRequest &request, const QByteArray &data)
{
    QEventLoop loop;
    QTimer timeoutTimer;
    (void)connect(&timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

    HTTPSender sender(this);
    (void)connect(&sender, &HTTPSender::errorReceivingReply, &loop, &QEventLoop::quit);
    (void)connect(&sender, &HTTPSender::receivedReply, &loop, &QEventLoop::quit);

    timeoutTimer.start(TIMEOUT_MSECS);
    sender.post(request, data);
    if (sender.isRunning())
    {
        loop.exec();
    }

    if (!timeoutTimer.isActive())
    {
        qDebug() << "Post reply timed out after " << TIMEOUT_MSECS << "ms";
        return CCIAgrirouter::NetworkReply();
    }

    timeoutTimer.stop();
    disconnect(&loop);

    QString error = sender.getErrorMessage();
    if (!error.isEmpty())
    {
        qDebug() << error;
    }

    return sender.getReply();
}

CCIAgrirouter::NetworkReply HTTPConnection::sendGetRequest(const QNetworkRequest &request)
{
    QEventLoop loop;
    QTimer timeoutTimer;
    timeoutTimer.setSingleShot(true);
    timeoutTimer.setInterval(TIMEOUT_MSECS);
    (void)connect(&timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

    HTTPSender sender(this);
    (void)connect(&sender, &HTTPSender::errorReceivingReply, &loop, &QEventLoop::quit);
    (void)connect(&sender, &HTTPSender::receivedReply, &loop, &QEventLoop::quit);

    timeoutTimer.start();
    sender.get(request);
    loop.exec();

    if (!timeoutTimer.isActive())
    {
        qDebug() << "Get reply timed out after " << TIMEOUT_MSECS << "ms";
        return CCIAgrirouter::NetworkReply();
    }

    timeoutTimer.stop();
    disconnect(&loop);

    return sender.getReply();
}
