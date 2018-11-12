//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef AGRIROUTERMESSAGE_2473FB9CFB70453ABA9E0E49E38FEA9C
#define AGRIROUTERMESSAGE_2473FB9CFB70453ABA9E0E49E38FEA9C

#include <google/protobuf/util/message_differencer.h>
#include "messaging/request/request.pb.h"
#include "messaging/response/response.pb.h"
#include "Utils.h"

namespace CCIAgrirouter
{

struct Request
{
    agrirouter::request::RequestEnvelope envelope;
    agrirouter::request::RequestPayloadWrapper payloadWrapper;

    Request()
    {
        envelope = agrirouter::request::RequestEnvelope::default_instance();
        payloadWrapper = agrirouter::request::RequestPayloadWrapper::default_instance();
    }

    void addRecipient(const std::string &recipient)
    {
        envelope.add_recipients(recipient);
    }

    void setPayload(google::protobuf::Message* message)
    {
        payloadWrapper.mutable_details()->PackFrom(*message, TYPE_URL_PREFIX.toStdString());
    }

    void clear()
    {
        envelope.Clear();
        payloadWrapper.Clear();
    }

    Request& operator =(const Request &other)
    {
        envelope = other.envelope;
        payloadWrapper = other.payloadWrapper;
        return *this;
    }

    bool operator ==(const Request &other) const
    {
        return (envelope.application_message_id() == other.envelope.application_message_id());
    }

    bool isEmpty() const
    {
        bool empty = google::protobuf::util::MessageDifferencer::Equals(envelope
                                                                        , agrirouter::request::RequestEnvelope::default_instance());
        empty &= google::protobuf::util::MessageDifferencer::Equals(payloadWrapper
                                                                    , agrirouter::request::RequestPayloadWrapper::default_instance());

        return empty;
    }
};

struct Response
{
    agrirouter::response::ResponseEnvelope envelope;
    agrirouter::response::ResponsePayloadWrapper payloadWrapper;

    Response()
    {
        envelope = agrirouter::response::ResponseEnvelope::default_instance();
        payloadWrapper = agrirouter::response::ResponsePayloadWrapper::default_instance();
    }

    Response(const agrirouter::response::ResponseEnvelope &env, const agrirouter::response::ResponsePayloadWrapper &payload)
    {
        envelope = env;
        payloadWrapper = payload;
    }

    void setEnvelope(const std::string &appMesssageId, qint32 responseCode, agrirouter::response::ResponseEnvelope_ResponseBodyType type)
    {
        envelope.set_application_message_id(appMesssageId);
        envelope.set_response_code(responseCode);
        envelope.set_type(type);
    }

    void setPayload(google::protobuf::Message* message)
    {
        payloadWrapper.mutable_details()->PackFrom(*message, TYPE_URL_PREFIX.toStdString());
    }

    void clear()
    {
        envelope.Clear();
        payloadWrapper.Clear();
    }

    bool operator ==(const Response &other) const
    {
        return (envelope.application_message_id() == other.envelope.application_message_id());
    }

    bool isEmpty() const
    {
        bool empty = google::protobuf::util::MessageDifferencer::Equals(envelope
                                                                        , agrirouter::response::ResponseEnvelope::default_instance());
        empty &= google::protobuf::util::MessageDifferencer::Equals(payloadWrapper
                                                                    , agrirouter::response::ResponsePayloadWrapper::default_instance());

        return empty;
    }
};

struct Reply
{
    qint32 statusCode;
    QString message;
};


struct RequestMessage
{
    QString m_sensorAlternateId;
    QString m_capabilityAlternateId;
    QString m_message;
    QString m_timestamp;

    RequestMessage(const QString &sensorAlternateId
                       , const QString &capabilityAlternateId
                       , const QString &message
                       , const QString &timestamp = Utils::getTimestamp())
    {
        m_sensorAlternateId = sensorAlternateId;
        m_capabilityAlternateId = capabilityAlternateId;
        m_message = message;
        m_timestamp = timestamp;
    }

    QString toJson()
    {
        return Utils::wrapMessageWithEnvelope(m_sensorAlternateId, m_capabilityAlternateId, m_message, m_timestamp);
    }
};

struct ResponseMessage
{
    QString m_sensorAlternateId;
    QString m_capabilityAlternateId;
    QString m_message;

    ResponseMessage()
    {

    }

    ResponseMessage(const QString &sensorAlternateId
                        , const QString &capabilityAlternateId
                        , const QString &message)
    {
        m_sensorAlternateId = sensorAlternateId;
        m_capabilityAlternateId = capabilityAlternateId;
        m_message = message;
    }

    ResponseMessage(const QString &responseString)
    {
        if (responseString.isEmpty())
        {
            return;
        }

        QJsonParseError jerror;
        QJsonDocument jdoc = QJsonDocument::fromJson(responseString.toUtf8(), &jerror);

        if ((int)jerror.error != QJsonParseError::NoError)
        {
            return;
        }

        QJsonArray responseArray = jdoc.array();
        QJsonObject response = responseArray.first().toObject();

        m_sensorAlternateId = response.value("sensorAlternateId").toString();
        m_capabilityAlternateId = response.value("capabilityAlternateId").toString();

        QJsonObject command = response.value("command").toObject();
        m_message = command.value("message").toString();
    }

    void print()
    {
        qDebug() << "sensorAlternateId:" << m_sensorAlternateId;
        qDebug() << "capabilityAlternateId:" << m_capabilityAlternateId;
        qDebug() << "message:" << m_message;
    }
};

struct ChunkMessage
{
    QString contextId;
    qint64 numberOfChunks;
    qint64 totalSize;
    QMap<qint64, QByteArray> data;
    QStringList messageIDs;

    bool operator ==(const ChunkMessage &other)
    {
        return (contextId == other.contextId);
    }
};

class AgrirouterMessage : public QObject
{
    Q_OBJECT
public:
    AgrirouterMessage(QObject* parent = nullptr);
    AgrirouterMessage(const Request &request, QObject* parent = nullptr);
    ~AgrirouterMessage();

    Request getRequest() const;
    QString getEncodedRequest() const;
    void setRequest(const Request &request);

    Response getResponse() const;
    void setResponse(const Response &response);

    void setRequestTimestamp();
    void setResponseTimestamp();

    QString getMessageId() const;
    QString getMessageType() const;
    RequestMessage getRequestMessage() const;

    bool isSent() const;
    void setSent(bool sent);
    void incrementSendCount();
    quint32 getSendCount();

    void incrementNoResponseCount();
    quint32 getNoResponseCount();

    bool isValid() const;
    bool operator ==(const AgrirouterMessage &other) const;

private:
    QString m_sensorAlternateId;
    QString m_capabilityAlternateId;
    Request m_request;
    Response m_response;
    google::protobuf::Timestamp m_requestTimestamp;
    google::protobuf::Timestamp m_responseTimestamp;
    bool m_sent;
    quint32 m_sendCount;
    quint32 m_noResponseCount;

};

}

#endif//AGRIROUTERMESSAGE_2473FB9CFB70453ABA9E0E49E38FEA9C
