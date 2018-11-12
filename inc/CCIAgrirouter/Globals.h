//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef GLOBALS_08172724BF43474892CB58AC650D9191
#define GLOBALS_08172724BF43474892CB58AC650D9191

#include <QString>
#include <QMetaType>

namespace CCIAgrirouter
{

// Max message poll time period (4 weeks)
// (60 minutes * 24 hours * 7 days * 4 weeks = 4 weeks in minutes) (-1 minute)
static const qint32 MAX_POLL_TIME_PERIOD = ((60 * 24 * 7 * 4) - 1);

static const QString TYPE_URL_PREFIX = "types.agrirouter.com";
static const QString TMP_DIR_NAME = "tmp";
static const QString TMP_CHUNK_DIR_NAME = "chunkInfo";
static const QString TMP_FILE_SUFFIX = "tmp";

namespace TechnicalMessageType
{
    // Internal message types
    static const QString CAPABILITIES = "dke:capabilities";
    static const QString SUBSCRIPTION = "dke:subscription";
    static const QString FEED_HEADER_QUERY = "dke:feed_header_query";
    static const QString FEED_MESSAGE_QUERY = "dke:feed_message_query";
    static const QString FEED_CONFIRM = "dke:feed_confirm";
    static const QString FEED_DELETE = "dke:feed_delete";
    static const QString LIST_ENDPOINTS = "dke:list_endpoints";
    static const QString LIST_ENDPOINTS_UNFILTERED = "dke:list_endpoints_unfiltered";
    static const QString CLOUD_ONBOARD_ENDPOINTS = "dke:cloud_onboard_endpoints";
    static const QString CLOUD_OFFBOARD_ENDPOINTS = "dke:cloud_offboard_endpoints";

    // Capability message types settable by application
    static const QString TASKDATA_ZIP = "iso:11783:-10:taskdata:zip";
    static const QString SHAPE_ZIP = "shp:shape:zip";
    static const QString DEVICE_DESCRIPTION = "iso:11783:-10:device_description:protobuf";
    static const QString TIMELOG = "iso:11783:-10:time_log:protobuf";
    static const QString IMAGE_PNG = "img:png";
    static const QString IMAGE_JPEG = "img:jpeg";
    static const QString NON_TELEMETRY = "dke:non_telemetry";
}

namespace CertificateType
{
    static const QString PEM = "PEM";
    static const QString P12 = "P12";
}

namespace MessageCode
{
    // ACK_WITH_FAILURE
    // Error: Unable to obtain details from the configuration module
    static const QString SYS_000001 = "SYS_000001";

    // ACK_WITH_FAILURE
    // Error: Unable to retrieve requested feed information
    static const QString SYS_000002 = "SYS_000002";

    // ACK_WITH_FAILURE
    // Error: Unable to process message
    static const QString SYS_000003 = "SYS_000003";

    // ACK_WITH_FAILURE
    // Error: Missing Endpoint Capabilities
    static const QString VAL_000001 = "VAL_000001";

    // ACK_WITH_FAILURE
    // Error: Endpoint is not able to send technical message type
    static const QString VAL_000002 = "VAL_000002";

    // ACK_WITH_FAILURE
    // Error: Missing Information Type assignment
    static const QString VAL_000003 = "VAL_000003";

    // ACK_WITH_FAILURE
    // Error: No recipients for this sender and info type
    static const QString VAL_000004 = "VAL_000004";

    // ACK_WITH_MESSAGES
    // Warning: Recipient is not allowed from this sender
    static const QString VAL_000005 = "VAL_000005";

    // ACK_WITH_FAILURE
    // Error: Subscription contains invalid message type(s)
    static const QString VAL_000006 = "VAL_000006";

    // ACK_WITH_MESSAGES
    // Warning: Capabilities contains invalid message type(s)
    static const QString VAL_000007 = "VAL_000007";

    // ACK_WITH_FAILURE
    // Error: Certification validations do not pass
    static const QString VAL_000008 = "VAL_000008";

    // ACK_WITH_FAILURE
    // Error: Account does not exist
    static const QString VAL_000009 = "VAL_000009";

    // ACK_WITH_FAILURE
    // Error: Account is not active
    static const QString VAL_000010 = "VAL_000010";

    // ACK_WITH_FAILURE
    // Error: Endpoint does not exist
    static const QString VAL_000011 = "VAL_000011";

    // ACK_WITH_FAILURE
    // Error: Endpoint is not active
    static const QString VAL_000012 = "VAL_000012";

    // ACK_WITH_FAILURE
    // Error: Account is not a Test Account
    static const QString VAL_000013 = "VAL_000013";

    // ACK_WITH_FAILURE
    // Error: Device Description Missing Information
    static const QString VAL_000014 = "VAL_000014";

    // ACK_WITH_FAILURE
    // Error: Device Descriptions Missing
    static const QString VAL_000015 = "VAL_000015";

    // ACK_WITH_FAILURE
    // Error: Team Set Context ID Missing
    static const QString VAL_000016 = "VAL_000016";

    // ACK_WITH_FAILURE
    // Error: Message missing required information
    static const QString VAL_000017 = "VAL_000017";

    // ACK_WITH_FAILURE
    // Error: Message missing required information
    static const QString VAL_000018 = "VAL_000018";

    // ACK_WITH_FAILURE
    // Error: Message cannot be chunked
    static const QString VAL_000019 = "VAL_000019";

    // ACK_WITH_FAILURE
    // Error: Team Set Context ID is not known
    static const QString VAL_000020 = "VAL_000020";

    // ACK_WITH_FAILURE
    // Error: Feed contains messages pending confirmation
    static const QString VAL_000200 = "VAL_000200";

    // ACK_WITH_FAILURE or ACK_WITH_MESSAGES
    // Error/Warning: Feed does not contain message requested
    static const QString VAL_000201 = "VAL_000201";

    // ACK_WITH_MESSAGES
    // Info: Feed does not contain any data for query
    static const QString VAL_000202 = "VAL_000202";

    // ACK_WITH_MESSAGES
    // Warning: Feed message is not pending confirmation
    static const QString VAL_000205 = "VAL_000205";

    // ACK_WITH_MESSAGES
    // Info: Feed message confirmation confirmed
    static const QString VAL_000206 = "VAL_000206";

    // ACK_WITH_MESSAGES
    // Info: Feed message cannot be deleted
    static const QString VAL_000207 = "VAL_000207";

    // ACK_WITH_MESSAGES
    // Info: Feed does not contain any data to be deleted
    static const QString VAL_000208 = "VAL_000208";

    // ACK_WITH_MESSAGES
    // Info: Feed message deleted
    static const QString VAL_000209 = "VAL_000209";

    // ACK_WITH_FAILURE
    // Error: Feed message no pending for confirmation
    static const QString VAL_000210 = "VAL_000210";

    // ACK_WITH_FAILURE
    // Error: Inbound payload size excedeed
    static const QString VAL_000211 = "VAL_000211";

    // CLOUD_REGISTRATIONS
    // Error: Unable to create cloud endpoint
    static const QString VAL_000300 = "VAL_000300";

    // ACK_WITH_MESSAGES
    // Error: Unable to offboard cloud endpoint
    static const QString VAL_000301 = "VAL_000301";

    // ACK_WITH_MESSAGES
    // Error: Unable to offboard cloud endpoint
    static const QString VAL_000302 = "VAL_000302";

    // ACK_WITH_FAILURE
    // Error: Sending endpoint is not a cloud application
    static const QString VAL_000303 = "VAL_000303";

    // ACK_WITH_FAILURE
    // Error: Unable to onboard into IoT CF for cloud application
    static const QString VAL_000304 = "VAL_000304";

    // ACK_WITH_MESSAGES
    // Error: Capabilities didn't change, so they are not updated
    static const QString NO_CAPABILITIES_CHANGE = "NO_CAPABILITIES_CHANGE";

    // ACK_WITH_MESSAGES
    // Error: Subscriptions didn't change, so they are not updated
    static const QString NO_SUBSCRIPTION_CHANGE = "NO_SUBSCRIPTION_CHANGE";
}

enum FileType
{
    FileType_NOTSET,
    FileType_TASKDATA_ZIP,
    FileType_SHAPE_ZIP,
    FileType_JPEG,
    FileType_PNG
};

// These are the status codes on HTTP level
enum HTTPStatusCode
{
    HTTPStatusCode_NOTSET = 0,
    HTTPStatusCode_OK = 200,
    HTTPStatusCode_OK_DATA_CREATED = 201,
    HTTPStatusCode_OK_NO_CONTENT = 204,
    HTTPStatusCode_BAD_REQUEST = 400
};

// These are the status codes on agrirouter level
enum AgrirouterResponseCode
{
    AgrirouterResponseCode_NOTSET = 0,
    AgrirouterResponseCode_OK = 200,
    AgrirouterResponseCode_OK_DATA_CREATED = 201,
    AgrirouterResponseCode_OK_NO_CONTENT = 204,
    AgrirouterResponseCode_ERROR_VALIDATION_FAILED = 400,
    AgrirouterResponseCode_ERROR_MESSAGE_TOO_LARGE = 413,
    AgrirouterResponseCode_ERROR_SERVER_OVERLOAD = 503
};

enum MessageTypeDirection
{
    MessageTypeDirection_NOTSET,
    MessageTypeDirection_SEND,
    MessageTypeDirection_RECEIVE,
    MessageTypeDirection_SEND_RECEIVE
};

struct SettingsParameters
{
    QByteArray sslPassphrase;
    QString sensorAlternateId;
    QString externalId;
    QString externalIdPrefix;
    QString iotServicesHost;
    QString dataDir;
    QString applicationId;
    QString certificationVersionId;
    QString maiOauthClientId;
    QString maiOauthClientSecret;
    QString capabilityAlternateId;
    QString deviceAlternateId;
    QString measures;
    QString commands;
    QString registrationUrl;
    QString certificateType;
    QString teamSetContextId;
    quint32 pollTryCount;
    quint32 timeoutMsecs;
    quint16 iotServicesPort;
};

}

Q_DECLARE_METATYPE(CCIAgrirouter::SettingsParameters)
Q_DECLARE_METATYPE(CCIAgrirouter::FileType)

#endif//GLOBALS_08172724BF43474892CB58AC650D9191
