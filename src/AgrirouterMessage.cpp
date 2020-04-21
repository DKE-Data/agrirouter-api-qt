//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "AgrirouterMessage.h"
#include "MessageConverter.h"
#include "Utils.h"

namespace CCIAgrirouter
{


AgrirouterMessage::AgrirouterMessage(QObject* parent)
    : QObject(parent)
    , m_sent(false)
    , m_sendCount(0)
    , m_noResponseCount(0)
{
    m_sensorAlternateId = Settings::getInstance().getSensorAlternateId();
    m_capabilityAlternateId = Settings::getInstance().getCapabilityAlternateId();
}

AgrirouterMessage::AgrirouterMessage(const Request &request, QObject *parent)
    : AgrirouterMessage(parent)
{
    m_request = request;
}

AgrirouterMessage::~AgrirouterMessage()
{

}

Request AgrirouterMessage::getRequest() const
{
    return m_request;
}

QString AgrirouterMessage::getEncodedRequest() const
{
    return MessageConverter::encodeRequest(m_request);
}

void AgrirouterMessage::setRequest(const Request &request)
{
    m_request = request;
}

Response AgrirouterMessage::getResponse() const
{
    return m_response;
}

void AgrirouterMessage::setResponse(const Response &response)
{
    m_response = response;
    setResponseTimestamp();
}

void AgrirouterMessage::setRequestTimestamp()
{
    qint64 msecs = QDateTime::currentMSecsSinceEpoch();
    qint64 seconds = msecs / 1000;
    qint32 nanos = static_cast<qint32>(msecs % 1000) * 1000000;

    m_requestTimestamp.set_seconds(seconds);
    m_requestTimestamp.set_nanos(nanos);
}

void AgrirouterMessage::setResponseTimestamp()
{
    qint64 msecs = QDateTime::currentMSecsSinceEpoch();
    qint64 seconds = msecs / 1000;
    qint32 nanos = static_cast<qint32>(msecs % 1000) * 1000000;

    m_responseTimestamp.set_seconds(seconds);
    m_responseTimestamp.set_nanos(nanos);
}

QString AgrirouterMessage::getMessageId() const
{
    if (!m_request.isEmpty())
    {
        return QString::fromStdString(m_request.envelope.application_message_id());
    }

    return QString();
}

QString AgrirouterMessage::getMessageType() const
{
    return QString::fromStdString(m_request.envelope.technical_message_type());
}

// This is the complete top level message
RequestMessage AgrirouterMessage::getRequestMessage() const
{
    QString timestamp = QString::number(m_requestTimestamp.seconds());
    return RequestMessage(m_sensorAlternateId, m_capabilityAlternateId, getEncodedRequest(), timestamp);
}

bool AgrirouterMessage::isSent() const
{
    return m_sent;
}

void AgrirouterMessage::setSent(bool sent)
{
    m_sent = sent;
}

void AgrirouterMessage::incrementSendCount()
{
    ++m_sendCount;
}

quint32 AgrirouterMessage::getSendCount()
{
    return m_sendCount;
}

void AgrirouterMessage::incrementNoResponseCount()
{
    ++m_noResponseCount;
}

quint32 AgrirouterMessage::getNoResponseCount()
{
    return m_noResponseCount;
}

bool AgrirouterMessage::isValid() const
{
    return !(m_request.isEmpty());
}

bool AgrirouterMessage::operator ==(const AgrirouterMessage &other) const
{
    return (this->getMessageId() == other.getMessageId());
}

}
