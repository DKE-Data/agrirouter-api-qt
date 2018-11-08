//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef HTTPCONNECTION_C9A80326995046999290D20A2BAEAFFC
#define HTTPCONNECTION_C9A80326995046999290D20A2BAEAFFC

#include <QObject>
#include "CCIAgrirouter/ICommunicationInterface.h"
#include <QDir>
#include "../Utils.h"

enum HTTPOperation
{
    HTTPOperation_NOTSET,
    HTTPOperation_POST,
    HTTPOperation_GET
};

struct HTTPRequestBundle
{
    QNetworkRequest request;
    QByteArray data;
    HTTPOperation operation;

    HTTPRequestBundle()
    {
        operation = HTTPOperation_NOTSET;
    }

    HTTPRequestBundle(QNetworkRequest r, HTTPOperation o, QByteArray d = QByteArray(0))
    {
        request = r;
        data = d;
        operation = o;
    }

    bool operator ==(const HTTPRequestBundle &other)
    {
        return ((request == other.request) && (operation == other.operation) && (data.size() == other.data.size()));
    }
};

class HTTPConnection : public QObject, public CCIAgrirouter::ICommunicationInterface
{
    Q_OBJECT
    Q_DISABLE_COPY(HTTPConnection)
public:
    HTTPConnection(QObject *parent = nullptr);
    HTTPConnection(const QString &host
                   , quint16 port
                   , const QString &certificateFileName
                   , const QString &certificateFilePath = QDir::separator()
                   , QObject *parent = nullptr);

    virtual ~HTTPConnection();

    virtual bool establishConnection(const QByteArray &passPhrase) override;
    virtual void closeConnection() override;
    virtual bool isConnected() override;

    virtual QSslConfiguration getSslConfiguration() override;
    QNetworkAccessManager* networkManager();

    virtual CCIAgrirouter::NetworkReply sendMessage(const QNetworkRequest &request) override;
    virtual CCIAgrirouter::NetworkReply sendMessage(const QNetworkRequest &request, const QByteArray &data) override;
    virtual CCIAgrirouter::NetworkReply sendGetRequest(const QNetworkRequest &request) override;

private:
    bool connectToHost();
    bool retryConnect();

    QNetworkAccessManager m_networkManager;
    QSslSocket m_sslSocket;
    qint32 m_reconnectCounter = 0;
    const qint32 MAX_RECONNECTS = 1;
    const qint32 TIMEOUT_MSECS = 4000;

};


#endif//HTTPCONNECTION_C9A80326995046999290D20A2BAEAFFC
