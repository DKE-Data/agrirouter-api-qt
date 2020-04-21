//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef ICOMMUNICATIONINTERFACE_5C73EC566933468484735CD06E6FD139
#define ICOMMUNICATIONINTERFACE_5C73EC566933468484735CD06E6FD139

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace CCIAgrirouter
{

enum CommunicationType
{
    CommunicationType_NOTSET,
    CommunicationType_HTTP,
    CommunicationType_MQTT
};

struct NetworkReply
{
    qint32 statusCode;
    QString reasonPhrase;
    QByteArray data;
    QNetworkReply::NetworkError errorCode;
    QString errorString;

    NetworkReply()
    {
        statusCode = 0;
        reasonPhrase = QString();
        data = QByteArray();
        errorCode = QNetworkReply::NetworkError::NoError;
        errorString = QString();
    }

    NetworkReply(QNetworkReply* reply)
    {
        statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        reasonPhrase = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        data = reply->readAll();
        errorCode = reply->error();
        errorString = reply->errorString();
    }
};

class ICommunicationInterface
{
public:
    virtual ~ICommunicationInterface(){}

    virtual bool establishConnection(const QByteArray &passPhrase) = 0;
    virtual void closeConnection() = 0;
    virtual bool isConnected() = 0;

    virtual QSslConfiguration getSslConfiguration() = 0;

    virtual NetworkReply sendMessage(const QNetworkRequest &request) = 0;
    virtual NetworkReply sendMessage(const QNetworkRequest &request, const QByteArray &data) = 0;
    virtual NetworkReply sendGetRequest(const QNetworkRequest &request) = 0;

    virtual CommunicationType getCommunicationType()
    {
        return m_communicationType;
    }

    virtual void setCommunicationType(const CommunicationType &communicationType)
    {
        m_communicationType = communicationType;
    }

    virtual void setUaaClientId(const QString &clientId)
    {
        m_uaaClientId = clientId;
    }

    virtual QString getUaaClientId()
    {
        return m_uaaClientId;
    }

    virtual void setUaaSecret(const QString &secret)
    {
        m_uaaSecret = secret;
    }

    virtual QString getUaaSecret()
    {
        return m_uaaSecret;
    }

    virtual void setCertificateFilePath(QString path)
    {
        m_certificateFilePath = path;
    }

    virtual void setCertificateFileName(QString filename)
    {
        m_certificateFileName = filename;
    }

    virtual void setHost(QString host)
    {
        m_host = host;
    }

    virtual void setPort(quint16 port)
    {
        m_port = port;
    }

protected:
    CommunicationType m_communicationType = CommunicationType_NOTSET;
    QString m_uaaClientId;
    QString m_uaaSecret;
    QString m_certificateFilePath;
    QString m_certificateFileName;
    QString m_host;
    quint16 m_port = 0;

};

}

#endif//ICOMMUNICATIONINTERFACE_5C73EC566933468484735CD06E6FD139
