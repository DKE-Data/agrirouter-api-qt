//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef MESSAGEQUEUE_B2B682CEC2394077BE5F0BC21AB4DBD2
#define MESSAGEQUEUE_B2B682CEC2394077BE5F0BC21AB4DBD2

#include <QObject>
#include <QQueue>
#include "AgrirouterMessage.h"

namespace CCIAgrirouter
{

class MessageQueue : public QObject
{   
    Q_OBJECT
    Q_DISABLE_COPY(MessageQueue)
public:
    explicit MessageQueue(QObject *parent = nullptr);
    ~MessageQueue();

    void addMessage(std::shared_ptr<AgrirouterMessage> message);
    void removeMessage(std::shared_ptr<AgrirouterMessage> message);
    std::shared_ptr<AgrirouterMessage> getMessageById(const QString &messageId);
    bool addResponse(const Response &response);
    bool containsMessage(std::shared_ptr<AgrirouterMessage> message);
    bool hasPendingMessages();
    void clearPendingHeaderRequests();
    void clear();

    void checkedForResponses();

    bool hasUnsentRequests();
    std::shared_ptr<AgrirouterMessage> getNextUnsentMessage();
    QList<std::shared_ptr<AgrirouterMessage>> getUnsentMessages();

    // Chunks
    void addChunkMessageToSend(std::shared_ptr<ChunkMessage> chunkMessage);
    void removeSentChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage);
    bool sendingChunkedFileFinished(const QString &chunkContextId);
    std::shared_ptr<ChunkMessage> getSentChunkMessageById(const QString &chunkContextId);

    void addReceivedChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage);
    void removeReceivedChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage);
    std::shared_ptr<ChunkMessage> getReceivedChunkMessageById(const QString &chunkContextId);

private:
    QQueue<std::shared_ptr<AgrirouterMessage>> m_queue;
    QList<std::shared_ptr<ChunkMessage>> m_chunksToSend;
    QList<std::shared_ptr<ChunkMessage>> m_receivedChunks;

    void saveMessageQueue();
    void readMessageQueue();
};

}

#endif // MESSAGEQUEUE_B2B682CEC2394077BE5F0BC21AB4DBD2
