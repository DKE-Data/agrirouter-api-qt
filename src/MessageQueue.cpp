//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "MessageQueue.h"
#include <QDebug>
#include "Settings.h"
#include "CCIAgrirouter/Globals.h"

namespace CCIAgrirouter
{

MessageQueue::MessageQueue(QObject *parent)
    : QObject(parent)
{
    readMessageQueue();
}

MessageQueue::~MessageQueue()
{
    saveMessageQueue();
}

void MessageQueue::addMessage(std::shared_ptr<AgrirouterMessage> message)
{
    if ((message == nullptr) || (!message->isValid()) || (containsMessage(message)))
    {
        return;
    }

    m_queue.enqueue(message);
    saveMessageQueue();
}

void MessageQueue::removeMessage(std::shared_ptr<AgrirouterMessage> message)
{
    if ((message == nullptr) || (!message->isValid()) || (!containsMessage(message)))
    {
        return;
    }

    for (const std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr) && (msg == message))
        {
            m_queue.removeOne(msg);
            saveMessageQueue();
            return;
        }
    }
}

std::shared_ptr<AgrirouterMessage> MessageQueue::getMessageById(const QString &messageId)
{
    for (const std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr) && (msg->getMessageId() == messageId))
        {
            return msg;
        }
    }

    return nullptr;
}

bool MessageQueue::addResponse(const Response &response)
{
    QString msgID = QString::fromStdString(response.envelope.application_message_id());

    for (std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr) && (msg->getMessageId() == msgID))
        {
            msg->setResponse(response);
            return true;
        }
    }

    return false;
}

bool MessageQueue::containsMessage(std::shared_ptr<AgrirouterMessage> message)
{
    return m_queue.contains(message);
}

bool MessageQueue::hasPendingMessages()
{
    for (const std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr)                          // Message exists
                && msg->isSent()                      // Message is sent (reply received)
                && (msg->getResponse().isEmpty())     // Message is not acknowledged (no response received)
                && (msg->getNoResponseCount() <= 2))  // Tried max 3 times to get a response
        {
            return true;
        }
    }

    return false;
}

void MessageQueue::clearPendingHeaderRequests()
{
    // Find all pending header requests without received response
    QList<std::shared_ptr<AgrirouterMessage>> messagesToRemove;
    for (std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr) && (msg->getMessageType() == TechnicalMessageType::FEED_HEADER_QUERY))
        {
            messagesToRemove.append(msg);
        }
    }

    // Remove all pending header requests
    for (std::shared_ptr<AgrirouterMessage> msg : messagesToRemove)
    {
        if (msg == nullptr)
        {
            continue;
        }

        m_queue.removeOne(msg);
    }

    // Save the queue
    saveMessageQueue();
}

void MessageQueue::clear()
{
    m_queue.clear();
}

void MessageQueue::checkedForResponses()
{
    QList<std::shared_ptr<AgrirouterMessage>> messagesToRemove;
    for (std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr)                        // Message exists
                && (msg->isSent())                  // Message is sent (reply received)
                && (msg->getResponse().isEmpty()))  // Message is not acknowledged (no response received)
        {
            msg->incrementNoResponseCount();

            // After 10 polls with no response, delete the message from queue
            // TODO: Add another timer to retry again later
            if (msg->getNoResponseCount() >= 10)
            {
                messagesToRemove.append(msg);
            }
        }
    }

    for (std::shared_ptr<AgrirouterMessage> msg : messagesToRemove)
    {
        if (msg != nullptr)
        {
            m_queue.removeOne(msg);
        }
    }
}

bool MessageQueue::hasUnsentRequests()
{
    for (std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr) && (!msg->isSent()))
        {
            return true;
        }
    }

    return false;
}

std::shared_ptr<AgrirouterMessage> MessageQueue::getNextUnsentMessage()
{
    for (std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr) && (!msg->isSent()))
        {
            return msg;
        }
    }

    return nullptr;
}

QList<std::shared_ptr<AgrirouterMessage>> MessageQueue::getUnsentMessages()
{
    QList<std::shared_ptr<AgrirouterMessage>> unsentMessages;

    for (std::shared_ptr<AgrirouterMessage> msg : m_queue)
    {
        if ((msg != nullptr) && (!msg->isSent()))
        {
            unsentMessages.append(msg);
        }
    }

    return unsentMessages;
}

void MessageQueue::addChunkMessageToSend(std::shared_ptr<ChunkMessage> chunkMessage)
{
    if (!m_chunksToSend.contains(chunkMessage))
    {
        m_chunksToSend.append(chunkMessage);
    }
}

void MessageQueue::addReceivedChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage)
{
    if (!m_receivedChunks.contains(chunkMessage))
    {
        m_receivedChunks.append(chunkMessage);
    }
}

void MessageQueue::removeSentChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage)
{
    if (m_chunksToSend.contains(chunkMessage))
    {
        m_chunksToSend.removeOne(chunkMessage);
    }
}

void MessageQueue::removeReceivedChunkMessage(std::shared_ptr<ChunkMessage> chunkMessage)
{
    if (m_receivedChunks.contains(chunkMessage))
    {
        m_receivedChunks.removeOne(chunkMessage);
    }
}

bool MessageQueue::sendingChunkedFileFinished(const QString &chunkContextId)
{
    for (std::shared_ptr<ChunkMessage> chunkMessage : m_chunksToSend)
    {
        if (chunkMessage->contextId == chunkContextId)
        {
            for (QString messageId : chunkMessage->messageIDs)
            {
                std::shared_ptr<AgrirouterMessage> message = getMessageById(messageId);
                if (message != nullptr)
                {
                    // Not all messages were sent, chunk is not finished
                    return false;
                }
            }

            // No message ID found, all message were sent. Chunk is finished
            return true;
        }
    }

    // Chunk not found, so it is not unfinished
    return true;
}

std::shared_ptr<ChunkMessage> MessageQueue::getSentChunkMessageById(const QString &chunkContextId)
{
    for (std::shared_ptr<ChunkMessage> chunkMessage : m_chunksToSend)
    {
        if (chunkMessage->contextId == chunkContextId)
        {
            return chunkMessage;
        }
    }

    return nullptr;
}

std::shared_ptr<ChunkMessage> MessageQueue::getReceivedChunkMessageById(const QString &chunkContextId)
{
    for (std::shared_ptr<ChunkMessage> chunkMessage : m_receivedChunks)
    {
        if (chunkMessage->contextId == chunkContextId)
        {
            return chunkMessage;
        }
    }

    return nullptr;
}

void MessageQueue::saveMessageQueue()
{
    //TODO
    // message queue needs to be stored
}

void MessageQueue::readMessageQueue()
{
    //TODO
    // message queue needs to be restored
}

}
