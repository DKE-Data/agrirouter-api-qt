//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef AGRIROUTERCLIENTPRIVATE_795170FE16A94B96B4B501BD8125670B
#define AGRIROUTERCLIENTPRIVATE_795170FE16A94B96B4B501BD8125670B

#include <QObject>
#include <QTimer>
#include "CCIAgrirouter/Globals.h"
#include "MessageQueue.h"

//Protobuf includes
#include "commons/message.pb.h"
#include "messaging/request/payload/endpoint/capabilities.pb.h"


namespace CCIAgrirouter
{

class AgrirouterClient;
class ICommunicationInterface;
struct Reply;

class AgrirouterClientPrivate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(AgrirouterClientPrivate)
public:
    AgrirouterClientPrivate(ICommunicationInterface *communicationInterface, AgrirouterClient* parent);
    ~AgrirouterClientPrivate();

    void initializeCommunicationInterface();
    void addCapability(const QString &technicalMessageType, const MessageTypeDirection &direction);
    bool certificateExists();
    bool establishConnection(const QByteArray &passPhrase);
    void closeConnection();
    void applicationReady();

    // Registration
    bool onboard(const QString &registrationCode);

    // Send
    /**
      Sends a message header request for messages of the given senders
       @param senders A list of externalIDs of senders
     */
    void requestMessageHeadersFromSenders(const QStringList &senders, bool forceCheckForChunks);

    /**
      Sends a message header request for messages which were sent in the last "periodInMinutes" minutes
       @param periodInMinutes The time period to check for new message in minutes
       @param forceCheckForChunks If true, the method sends the request directly even if the agrirouter client is busy
              (Don't wait for the next periodic header request)
     */
    void requestMessageHeadersFromPeriod(quint32 periodInMinutes, bool forceCheckForChunks);

    void addRequestToMessageQueue(const Request &request);
    void addChunkMessageToSend(std::shared_ptr<ChunkMessage> chunkMessage);
    void tryToSendUnfinishedRequests(bool forceSend);

    // Set/Get
    void setNewTeamSetContextId();
    qint32 getNextSeqNo();
    agrirouter::request::payload::endpoint::CapabilitySpecification *getCapabilities();
    bool isConnected();
    bool isSending() const;

Q_SIGNALS:
    void sendFileResult(const QString &messageId, FileType fileType, bool success);

private:
    bool communicationInterfaceAvailable();
    bool readCapabilitiesFromFile();
    void settingsChanged();

    // Send
    void requestMessageByMessageId(const QString &messageId);
    void confirmMessageFeed(const QStringList &messageIDs);
    void deleteMessageFeed(const QString &messageId);
    void sendUnfinishedRequests();

    // Response poll
    void startPollForResponses();
    void onResponsePollTimeout();
    QList<Response> pollForResponses();

    // Reponse handling
    bool handleReceivedResponse(const Response &response);

    // Handle different payloads
    bool handleMessagesPayload(const google::protobuf::Any &payload, const QString &chunkContextId = QString());
    bool handleFeedHeaderListPayload(const google::protobuf::Any &payload);
    QStringList handleFeedMessagePayload(const google::protobuf::Any &payload);
    bool handleFeedFailedMessagePayload(const google::protobuf::Any &payload);
    bool handleEndpointsListingPayload(const google::protobuf::Any &payload);

    // Tmp chunk file handling
    /**
     * Reads all tmp chunk files that were created earlier.
     * There may be chunk info files containing information about unfinished chunk contexts
     * as serialized (and base64 encoded) protobuf.
     * There may also be chunk data files containing data from already received chunks.
     */
    void readTmpChunkFiles();

    /**
     * Writes chunk information as serialized (and base64 encoded) protobuf into a tmp file
     * The filename is the chunk context id with the suffix ".tmp"
     * @param chunkMessage The struct object containing all chunk information
     */
    void writeTmpChunkInfoFile(std::shared_ptr<ChunkMessage> chunkMessage);

    /**
     * Writes data of a received chunk into a tmp chunk data file.
     * All files are deleted since the chunk is completed and the resulting file is created.
     * @param currentChunk The number of the current chunk (starts at 1, not at 0)
     * @param chunkContextId The ID representing the chunk context
     * @param data The data of the received chunk
     */
    void writeTmpChunkDataFile(qint64 currentChunk, const QString &chunkContextId, const QByteArray &data);

    /**
     * Deletes all files regarding the given chunk context
     * This is called when all chunks are received and the resulting file is created
     * @param contextId The ID of the chunk context
     */
    void removeTmpChunkFiles(const QString &contextId);

    ICommunicationInterface* const m_communicationInterface;
    MessageQueue m_messageQueue;
    qint32 m_seqNo = 0;
    agrirouter::request::payload::endpoint::CapabilitySpecification* m_capabilities = nullptr;
    QString m_certificateName;
    bool m_sending = false;

    /**
     * This is true while chunk messages are being received.
     * This is needed to trigger another message check directly after confirming a chunk message
     * Wait time for the periodic check will be skipped then
     */
    bool m_receivingChunks = false;
    QTimer m_responsePollTimer;
    AgrirouterClient* const m_q;

};

}

#endif//AGRIROUTERCLIENTPRIVATE_795170FE16A94B96B4B501BD8125670B
