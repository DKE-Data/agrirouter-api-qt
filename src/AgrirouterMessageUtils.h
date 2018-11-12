//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef AGRIROUTERMESSAGEUTILS_74310D38D16C4E4C8C3EC6134B2DDC2E
#define AGRIROUTERMESSAGEUTILS_74310D38D16C4E4C8C3EC6134B2DDC2E

#include "AgrirouterMessage.h"
#include "CCIAgrirouter/Globals.h"
#include <QDateTime>
#include <QDebug>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/util/delimited_message_util.h>

//Protobuf includes
#include "commons/message.pb.h"
#include "messaging/response/payload/feed/feed-response.pb.h"

namespace CCIAgrirouter
{
namespace AgrirouterMessageUtils
{

static agrirouter::request::RequestEnvelope createRequestHeader(const QString &messageId
                                                                , qint32 seqNo
                                                                , const QString &messageType
                                                                , agrirouter::request::RequestEnvelope_Mode mode
                                                                , const QStringList &recipients = QStringList())
{
    agrirouter::request::RequestEnvelope header;
    header.set_application_message_id(messageId.toStdString());
    header.set_application_message_seq_no(seqNo);
    header.set_technical_message_type(messageType.toStdString());
    header.set_mode(mode);

    qint64 msecs = QDateTime::currentMSecsSinceEpoch();
    qint64 seconds = msecs / 1000;
    qint32 nanos = static_cast<qint32>(msecs % 1000) * 1000000;
    header.mutable_timestamp()->set_seconds(seconds);
    header.mutable_timestamp()->set_nanos(nanos);

    for (QString rec : recipients)
    {
        header.add_recipients(rec.toStdString());
    }

    return header;
}

static agrirouter::request::RequestPayloadWrapper createRequestBody(google::protobuf::Message *message)
{
    if (!message)
    {
        return agrirouter::request::RequestPayloadWrapper::default_instance();
    }

    agrirouter::request::RequestPayloadWrapper body;
    body.mutable_details()->PackFrom(*message, TYPE_URL_PREFIX.toStdString());

    return body;
}

static void printMessages(agrirouter::commons::Messages *messages)
{
    for (qint32 i = 0; i < messages->messages_size(); ++i)
    {
        agrirouter::commons::Message msg = messages->messages(i);
        qDebug() << "[" << QString::fromStdString(msg.message_code()) << "] " << QString::fromStdString(msg.message());
    }
}

static void printHeaderFeed(agrirouter::feed::response::HeaderQueryResponse_Feed* feed)
{
    qDebug() << "Sender-ID: " << QString::fromStdString(feed->sender_id());
    for (agrirouter::feed::response::HeaderQueryResponse_Header header : feed->headers())
    {
        qDebug() << "- Message-ID: " << QString::fromStdString(header.message_id());
        qDebug() << "- Technical message type: " << QString::fromStdString(header.technical_message_type());
        qDebug() << "- Context-ID: " << QString::fromStdString(header.team_set_context_id());
    }
}

}
}

#endif//AGRIROUTERMESSAGEUTILS_74310D38D16C4E4C8C3EC6134B2DDC2E
