//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef AGRIROUTERCLIENT_795170FE16A94B96B4B501BD8125670B
#define AGRIROUTERCLIENT_795170FE16A94B96B4B501BD8125670B

#include "CCIAgrirouter_export.h"
#include "CCIAgrirouter/Globals.h"
#include "ICommunicationInterface.h"

//Protobuf includes
#include "commons/message.pb.h"
#include "messaging/request/payload/efdi/grpc-efdi.pb.h"

namespace CCIAgrirouter
{

class AgrirouterClientPrivate;
class MessageQueue;
struct Request;
struct Response;
struct ChunkMessage;

class CCIAGRIROUTER_EXPORT AgrirouterClient : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(AgrirouterClient)
public:
    AgrirouterClient(ICommunicationInterface *communicationInterface, QObject *parent = nullptr);
    ~AgrirouterClient();

    /**
      Updates all settings values.
       @param params A struct which contains all settings values.
     */
    void setSettingsParameters(const SettingsParameters &params);

    /**
      Connects the communication interface to the agrirouter host.
     */
    void establishConnection();

    /**
      Closes the active connection to the agrirouter host.
     */
    void closeConnection();

    /**
      Checks if the communication interface has a connection to the agrirouter.
       @return true if connection is active, false if not.
     */
    bool isConnected();

    /**
     * Shall be called by the application when it has finished starting up.
       Checks for received chunk data of unfinished chunked messages.
     */
    void applicationReady();

    /**
      Adds a new capability to the local capability-list.
      This needs to be done before sending the capabilities to the agrirouter.
       @param technicalMessageType The message type of the capability.
       @param direction The direction (SEND, RECEIVE or SEND_RECEIVE) of the capability.
     */
    void addCapability(const QString &technicalMessageType, const MessageTypeDirection &direction);

    /**
      Checks if there is a certificate in the data dir which belongs to the current active externalID.
       @return true if there is a certificate with the filename "{externalID}.pem" and "{externalID}.key" OR "{externalID}.p12" in the data dir.
     */
    bool hasCertificate();

    /**
       @return true if capabilites were set with addCapability(..) before, false if not.
     */
    bool hasCapabilities();

    /**
      Sends an onboard request in order to register this endpoint.
       @param registrationCode The generated registration code from the agrirouter website.
     */
    void registerEndpoint(const QString &registrationCode);

    /**
      Sends a capability specification with the capabilities which were set with addCapability(..) before.
     */
    void sendCapabilities();

    /**
      Sends a subscription of the given technical message type to the agrirouter.
       @param technicalMessageTypes The message type to be subscribed.
     */
    void sendSubscription(QStringList technicalMessageTypes);

    /**
      Sends a message with the given filedata as payload.
      Before sending, the method determines the message type and the send mode (direct or publish).
      It also checks if the message needs to be sent in chunks or not.
       @param filepath The full path to the file to be sent.
       @param filetype The datatype of the file.
       @param recipients The receiver endpointIDs in case the message shall be sent directly to other endpoints.
                         If recipients is empty, the message will be published.
     */
    void sendFile(const QString &filepath, FileType filetype, const QStringList &recipients);

    /**
      Sends a device description to the agrirouter.
      This creates a machine in the agrirouter endpoint list.
       @param deviceDescription The device description of the machine.
     */
    void sendDeviceDescription(efdi::ISO11783_TaskData &deviceDescription);

    /**
      Sends a request for an unfiltered endpoint list to the agrirouter.
     */
    void requestEndpointList();

    /**
      Sends a request for a filtered endpoint list to the agrirouter.
       @param messageType Only show endpoints which support this message type.
       @param direction Only show endpoints who can SEND, RECEIVE or SEND_RECEIVE the given message type.
     */
    void requestEndpointList(const QString &messageType, MessageTypeDirection direction);

    /**
      Sends a message header request.
      Calls the method requestMessageHeadersFromSenders(..).
       @param senders The sender IDs of which messages shall be received.
       @param forceCheckForChunks Sends the request directly, even if the client is busy.
              (This shall be used when checking for more chunks to receive)
     */
    void checkForNewMessages(QStringList senders, bool forceCheckForChunks);

    /**
      Sends a message header request.
      Calls the method requestMessageHeadersFromPeriod(..).
       @param periodInMinutes The time period in minutes that shall be checked.
       @param forceCheckForChunks Sends the request directly, even if the client is busy.
              (This shall be used when checking for more chunks to receive)
     */
    void checkForNewMessages(quint32 periodInMinutes, bool forceCheckForChunks);

    /**
      Returns the externalID.
       @return The currently active externalID.
     */
    QString getExternalId();

    /**
      Deletes certificate files that correspond to the given externalID. If the param is empty, all certificate files will be deleted.
       @param externalId The corresponding externalID of the certificate files to be deleted.
     */
    void deleteCertificateFiles(const QString &externalId = QString());

    /**
      Deletes all certificate files, resets the settings to default and creates a new teamset context ID.
     */
    void resetToDefault();

Q_SIGNALS:
    /**
      Is emitted if the client finished connecting to the host.
     */
    void connected();

    /**
      Is emitted if the client has disconnected from the host.
     */
    void disconnected();

    /**
      Is emitted if the settings has been changed in the lib.
      This shall be used to update the settings in the app.
       @param params A struct which contains all settings values.
     */
    void settingsChanged(const SettingsParameters &params);

    /**
      Informs the app that the endpoint is not registered anymore.
      This happens if the endpoint is deleted from the agrirouter account.
     */
    void receivedBadRequest();

    /**
      Is emitted if the repsonse poll fails because there is no internet connection.
     */
    void noInternetConnection();

    /**
    * Informs the app that an endpoint list has been received.
    * @param endpoints The endpoint list.
                       The first QMap param (key) is the endpoint-ID.
    *                  The second param (value) is the endpoint name.
    */
    void receivedEndpointList(const QMap<QString, QString> &endpoints);

    /**
      Is emitted if the response poll fails.
     */
    void receivedNoResponse();

    /**
      Is emitted if a file has benn received.
       @param filedata The raw (not encoded) binary data of the received file.
       @param filetype The datatype of the file (e.g. FileType_TASKDATA_ZIP).
     */
    void receivedFile(const QByteArray &filedata, FileType filetype);

    /**
      Is emitted if a server message has been received from the agrirouter.
       @param messageCode The message code of the received server message (e.g. "VAL_000001").
                          (The message codes are listed in Globals.h)
       @param message The full message text.
       @param chunkContextId The chunk context ID if the server message is a response to a chunk message.
     */
    void receivedServerMessage(const QString &messageCode, const QString &message, const QString &chunkContextId);

    /**
      Is emitted if a response to checkForNewMessages() has been received.
      If there are new messages available, they will be requested automatically.
       @param newMessages True if there are new messages available, false if not.
     */
    void checkForNewMessagesResult(bool newMessages);

    /**
      Is emitted if the registration process is finished.
       @param success True if the registration was successful, false if not.
     */
    void registerEndpointResult(bool success);

    /**
      Is emitted if sending the capabilities is finished.
       @param success True if sending the capabilities message was successful, false if not.
     */
    void sendCapabilitiesResult(bool success);

    /**
      Is emitted if sending a subscription is finished.
       @param success True if sending the subscription message was successful, false if not.
     */
    void sendSubscriptionResult(bool success);

    /**
      Is emitted if sending a file is finished.
       @param filename The name of the sent file.
       @param filetype The datatype of the sent file.
       @param success True if sending the file was successful, false if not.
     */
    void sendFileResult(const QString &filename, FileType filetype, bool success);

private Q_SLOTS:
    /**
      Will be called from the private agrirouter client class (AgrirouterClientPrivate) if sending a file is finished.
       @param messageId The messageID of the sent message.
       @param fileType The datatype of the sent file.
       @param success True if sending the file was successful, false if not.
     */
    void onSendFileResult(const QString &messageId, FileType fileType, bool success);

private:
    /**
    * Creates a request for a chunk, appends it to the message queue and sends it.
    * @param chunkMessage The chunked message containing all required data.
    * @param recipients The receiver endpointIDs in case the message shall be sent directly. If this is empty, the message will be published.
    * @param technicalMessageType The message type of the full message (so for every chunk message as well).
    */
    void sendChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage, const QStringList &recipients, const QString &technicalMessageType);

    /**
      If there is a "send file" message with the given ID, the method returns the path to the file to be sent.
       @param messageId The messageID of the "send file" message.
       @return The file path if there is a message, an empty QString if not.
     */
    QString getFilePathForMessageId(const QString &messageId);

    /**
      The private client class with detailed methods and attributes which do not need to be accessed from outside the lib.
     */
    AgrirouterClientPrivate* const m_d;

    /**
     * Stores the paths of files to send together with the corresponding message-ID (or chunk-context-ID)
     * @return QMap key: message-ID or chunk-context-ID
     *         QMap value: full file path
     */
    QMap<QString, QString> m_filesToSend;

};

}

#endif//AGRIROUTERCLIENT_795170FE16A94B96B4B501BD8125670B
