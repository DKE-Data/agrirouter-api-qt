//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef UTILS_9752824A51F1490DBE893290177DB3A0
#define UTILS_9752824A51F1490DBE893290177DB3A0

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QUuid>
#include <QTextStream>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/util/delimited_message_util.h>
#include "messaging/request/request.pb.h"
#include "messaging/response/response.pb.h"
#include "Settings.h"
#include "CCIAgrirouter/Globals.h"

namespace CCIAgrirouter
{
namespace Utils
{

static QString createUuid()
{
    // Create QUuid
    QUuid uuid = QUuid::createUuid();
    // Convert QUuid to QString
    QString uuidString = uuid.toString();
    // Remove {...} braces
    uuidString = uuidString.mid(1, (uuidString.size() - 2));

    return uuidString;
}

static QString getTimestamp()
{
    return QString::number(QDateTime::currentMSecsSinceEpoch());
}

// New function with private key and certificate
// (Corresponding passPhrase is stored in Settings)
static bool createCertificateFiles(const QString &certificate, const QString &certificateFileName)
{
    QString splitString("\n-----END ENCRYPTED PRIVATE KEY-----\n");
    QStringList stringList = certificate.split(splitString);

    if (stringList.size() != 2)
    {
        return false;
    }

    QString privateKeyString = stringList.at(0) + splitString;
    QString certificateString = stringList.at(1);

    const Settings &settings = Settings::getInstance();

    QFile keyFile(settings.getDataDir() + QDir::separator() + certificateFileName + ".key");
    if (keyFile.exists())
    {
        if (!keyFile.remove())
        {
            qWarning() << "Cannot delete existing certificate file";
            return false;
        }
    }

    if (keyFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&keyFile);
        stream << privateKeyString;
    }

    keyFile.close();

    QFile pemFile(settings.getDataDir() + QDir::separator() + certificateFileName + ".pem");
    if (pemFile.exists())
    {
        if (!pemFile.remove())
        {
            qWarning() << "Cannot delete existing certificate file";
            return false;
        }
    }

    if (pemFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&pemFile);
        stream << certificateString;
    }

    pemFile.close();

    return true;
}

static void deleteCertificateFiles(const QString &externalId = QString())
{
    if (externalId == "-")
    {
        qDebug() << "Delete nothing. ExternalID is empty.";
        return;
    }

    const Settings &settings = Settings::getInstance();
    QDir dataDir(settings.getDataDir());
    QFileInfoList fileInfoList = dataDir.entryInfoList(QStringList() << "*.pem" << "*.key" << "*.p12");
    for (auto it = fileInfoList.begin(); it != fileInfoList.end(); ++it)
    {
        QFile currentFile(it->absoluteFilePath());

        // If externalID is not empty, check if fileName contains the ID (Only delete files containing the ID in the fileName)
        if ((!externalId.isEmpty()) && (!currentFile.fileName().contains(externalId)))
        {
            continue;
        }

        if (currentFile.remove())
        {
            qDebug() << "Deleted certificate file:" << currentFile.fileName();
        }
        else
        {
            qWarning() << "Cannot delete certificate file:" << currentFile.fileName();
        }
    }
}

static bool fileExists(QString path)
{
    QFileInfo check_file(path);
    return check_file.exists() && check_file.isFile();
}

static QByteArray readFile(const QString &filename)
{
    QByteArray data;
    QFile file(filename);
    if (!file.exists())
    {
        return QByteArray();
    }

    if (file.open(QIODevice::ReadOnly))
    {
        data = file.readAll();
        file.close();
    }

    return data;
}

static bool writeFile(const QString &filename, QByteArray data)
{
    // Delete file if it already exists
    QFile file(filename);
    if (file.exists())
    {
        if (!file.remove())
        {
            qDebug() << "Cannot delete existing file";
            return false;
        }
    }

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.close();
        return true;
    }

    return false;
}

static QByteArray encodeBase64(QByteArray data)
{
    QByteArray result;
    for (qint32 i = 0; i < data.size(); i+=3)
    {
        QByteArray threeBytes;
        for (qint32 j = 0; j < 3; ++j)
        {
            qint32 current = i+j;
            if (current >= data.size())
            {
                break;
            }

            threeBytes.append(data.at(current));
        }

        result.append(threeBytes.toBase64());
    }

    return result;
}

static QByteArray decodeBase64(QByteArray data)
{
    QByteArray result;
    for (qint32 i = 0; i < data.size(); i+=4)
    {
        QByteArray fourBytes;
        for (qint32 j = 0; j < 4; ++j)
        {
            qint32 current = i+j;
            if (current >= data.size())
            {
                break;
            }

            fourBytes.append(data.at(current));
        }

        result.append(QByteArray::fromBase64(fourBytes));
    }

    return result;
}

static QByteArray encodeVarint(qint32 number)
{
    QByteArray output;
    qint32 outputSize = 0;
    //While more than 7 bits of data are left, occupy the last output byte
    // and set the next byte flag
    while (number > 127)
    {
        //|128: Set the next byte flag
        output[outputSize] = static_cast<char>((static_cast<uint8_t>(number) & 127) | 128);
        //Remove the seven bits we just wrote
        number >>= 7;
        outputSize++;
    }

    output[outputSize++] = static_cast<char>(static_cast<uint8_t>(number) & 127);
    return output;
}

static quint32 getId()
{
    static quint32 s_id;
    return ++s_id;
}

// JSON will be replaced with protobuf in the futue
static QStringList getMessagesFromResponse(const QString &data)
{
    QStringList messageList;
    QJsonObject responseJson;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    // check validity of the document
    if(!doc.isNull())
    {
        if(doc.isArray())
        {
            responseJson = doc.array().first().toObject();
        }
        else
        {
            qWarning() << "Error";
            return QStringList();
        }
    }

    QJsonArray messages = responseJson["messages"].toArray();
    for (qint32 i = 0; i < messages.size(); ++i)
    {
        QJsonObject message = messages.at(i).toObject();
        QJsonValue value = message.value("message");

        messageList.append(value.toString());
    }

    return messageList;
}

static void printErrorMessageFromReply(const QByteArray &data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);

    // Check validity of the document
    if(doc.isNull() || (!doc.isObject()) || (doc.object().isEmpty()))
    {
        return;
    }

    QJsonObject jsonObject = doc.object();
    QJsonValue errorValue = jsonObject.value("error");
    QJsonObject errorObject = errorValue.toObject();

    QString code = errorObject.value("code").toString();
    QString message = errorObject.value("message").toString();
    QString target = errorObject.value("target").toString();
    QString details = errorObject.value("details").toString();

    if (!code.isEmpty())
    {
        qDebug() << "Error " << code << ": " << message;
        if (!target.isEmpty())
        {
            qDebug() << "Target: " << target;
        }

        if (!details.isEmpty())
        {
            qDebug() << "Details: " << details;
        }
    }
}

static QString wrapMessageWithEnvelope(const QString &sensorAlternateId, const QString &capabilityAlternateId, const QString &encodedMessage, const QString &timestamp)
{
    return "{\"sensorAlternateId\":\"" + sensorAlternateId  + "\",\"capabilityAlternateId\":\""
            + capabilityAlternateId + "\",\"measures\":[[\"" + encodedMessage + "\",\"" + timestamp + "\"]]}";
}

static QString getHostUrl(QString measures, QString commands)
{
    QString hostPrefix = "https://";

    // Check if the URLs start with "https://"
    // If not, the URLs are not valid
    if ((!measures.startsWith(hostPrefix)) || (!commands.startsWith(hostPrefix)))
    {
        return QString();
    }

    // Remove "https://" from URLs (will be added again later)
    measures = measures.remove(0, hostPrefix.length());
    commands = commands.remove(0, hostPrefix.length());

    QStringList splittedMeasures = measures.split("/", QString::SkipEmptyParts, Qt::CaseInsensitive);
    QStringList splittedCommands = commands.split("/", QString::SkipEmptyParts, Qt::CaseInsensitive);

    // Only return if both URLs have the same host URL
    QString hostUrl = splittedMeasures.first();
    if (hostUrl == splittedCommands.first())
    {
        // Add "https://"
        hostUrl.prepend(hostPrefix);
        return hostUrl;
    }

    return QString();
}

static QDir getTmpDir()
{
    QString dataDir = Settings::getInstance().getDataDir();
    QDir tmpDir(dataDir + QDir::separator() + TMP_DIR_NAME);
    if (!tmpDir.exists())
    {
        if (!QDir::root().mkpath(tmpDir.absolutePath()))
        {
            qWarning() << "Cannot create tmp directory";
            return QDir();
        }
    }

    return tmpDir;
}

static QDir getTmpChunkDir()
{
    QDir tmpDir = Utils::getTmpDir();
    if (!tmpDir.exists())
    {
        return QDir();
    }

    QDir tmpChunkDir(tmpDir.absolutePath() + QDir::separator() + TMP_CHUNK_DIR_NAME);
    if (!tmpChunkDir.exists())
    {
        if (!QDir::root().mkpath(tmpChunkDir.absolutePath()))
        {
            qWarning() << "Cannot create tmp chunk directory";
            return QDir();
        }
    }

    return tmpChunkDir;
}

}
}

#endif//UTILS_9752824A51F1490DBE893290177DB3A0
