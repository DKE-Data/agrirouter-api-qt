//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "MessageConverter.h"
#include "AgrirouterMessageUtils.h"
#include "Utils.h"
#include <google/protobuf/io/coded_stream.h>

namespace CCIAgrirouter
{

// Local encoding

QString MessageConverter::encodeRequest(const Request &request)
{
    std::string result;
    google::protobuf::io::StringOutputStream outputStream(&result);

    if (!google::protobuf::util::SerializeDelimitedToZeroCopyStream(request.envelope, &outputStream))
    {
        qWarning() << "Error encoding message envelope";
        return QString();
    }

    if (!google::protobuf::util::SerializeDelimitedToZeroCopyStream(request.payloadWrapper, &outputStream))
    {
        qWarning() << "Error encoding message payloadWrapper";
        return QString();
    }

    QByteArray resultBytes(result.data(), static_cast<int>(result.length()));
    QByteArray encodedResult = Utils::encodeBase64(resultBytes);
    return QString::fromUtf8(encodedResult);
}

QString MessageConverter::encodeResponse(const Response &response)
{
    std::string result;
    google::protobuf::io::StringOutputStream outputStream(&result);

    if (!google::protobuf::util::SerializeDelimitedToZeroCopyStream(response.envelope, &outputStream))
    {
        qWarning() << "Error encoding message envelope";
        return QString();
    }

    if (!google::protobuf::util::SerializeDelimitedToZeroCopyStream(response.payloadWrapper, &outputStream))
    {
        qWarning() << "Error encoding message payloadWrapper";
        return QString();
    }

    QByteArray resultBytes(result.c_str(), static_cast<int>(result.length()));
    QByteArray encodedResult = Utils::encodeBase64(resultBytes);
    return QString::fromUtf8(encodedResult);
}


// Local decoding

Request MessageConverter::decodeRequest(const QString &encoded)
{
    Request request;
    QByteArray decodedRequest = Utils::decodeBase64(encoded.toUtf8());

    google::protobuf::io::ArrayInputStream inputStream(decodedRequest, decodedRequest.length());
    google::protobuf::io::CodedInputStream codedStream(&inputStream);

    quint32 envelopeLength;
    if (!codedStream.ReadVarint32(&envelopeLength))
    {
        qDebug() << "Error: Unable to parse message";
        return Request();
    }

    char envelopeBuffer[envelopeLength];
    if (codedStream.ReadRaw(&envelopeBuffer, envelopeLength))
    {
        request.envelope.ParseFromArray(&envelopeBuffer, envelopeLength);
    }

    quint32 payloadLength;
    if (!codedStream.ReadVarint32(&payloadLength))
    {
        qDebug() << "Error: Unable to parse message";
        return Request();
    }

    char payloadBuffer[payloadLength];
    if (codedStream.ReadRaw(&payloadBuffer, payloadLength))
    {
        request.payloadWrapper.ParseFromArray(&payloadBuffer, payloadLength);
    }

    return request;
}

Response MessageConverter::decodeResponse(const QString &encoded)
{
    if (encoded.isEmpty())
    {
        return Response();
    }

    Response response;
    QByteArray decodedResponse = Utils::decodeBase64(encoded.toUtf8());

    google::protobuf::io::ArrayInputStream inputStream(decodedResponse, decodedResponse.length());
    google::protobuf::io::CodedInputStream codedStream(&inputStream);

    quint32 envelopeLength;
    if (!codedStream.ReadVarint32(&envelopeLength))
    {
        qDebug() << "Error: Unable to parse message";
        return Response();
    }

    char envelopeBuffer[envelopeLength];
    if (codedStream.ReadRaw(&envelopeBuffer, envelopeLength))
    {
        response.envelope.ParseFromArray(&envelopeBuffer, envelopeLength);
    }

    quint32 payloadLength;
    if (!codedStream.ReadVarint32(&payloadLength))
    {
        qDebug() << "Error: Unable to parse message";
        return Response();
    }

    char payloadBuffer[payloadLength];
    if (codedStream.ReadRaw(&payloadBuffer, payloadLength))
    {
        response.payloadWrapper.ParseFromArray(&payloadBuffer, payloadLength);
    }

    return response;
}

QList<ResponseMessage> MessageConverter::decodeResponseString(const QString &responseString)
{
    if (responseString.isEmpty())
    {
        return QList<ResponseMessage>();
    }

    QJsonParseError jerror;
    QJsonDocument jdoc = QJsonDocument::fromJson(responseString.toUtf8(), &jerror);

    if ((int)jerror.error != QJsonParseError::NoError)
    {
        return QList<ResponseMessage>();
    }

    QList<ResponseMessage> responseMessages;

    QJsonArray responseArray = jdoc.array();
    for (qint32 i = 0; i < responseArray.size(); ++i)
    {
        QJsonObject response = responseArray.at(i).toObject();

        ResponseMessage responseMessage;

        responseMessage.m_sensorAlternateId = response.value("sensorAlternateId").toString();
        responseMessage.m_capabilityAlternateId = response.value("capabilityAlternateId").toString();

        QJsonObject command = response.value("command").toObject();
        responseMessage.m_message = command.value("message").toString();

        responseMessages.append(responseMessage);
    }

    return responseMessages;
}

}
