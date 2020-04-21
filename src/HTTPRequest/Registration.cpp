//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "Registration.h"

#include <QUuid>
#include "CCIAgrirouter/ICommunicationInterface.h"
#include "CCIAgrirouter/Globals.h"
#include "Utils.h"
#include "Settings.h"

namespace CCIAgrirouter
{

Registration::Registration(ICommunicationInterface *communicationInterface, QObject *parent)
    : QObject(parent)
    , m_communicationInterface(communicationInterface)
{

}

Registration::~Registration()
{

}

bool Registration::postOnboard(const QString &registrationCode, const QString &certificateFileName)
{
    Settings &settings = Settings::getInstance();

    QString registrationUrl = settings.getRegistrationUrl();
    QString applicationId = settings.getApplicationId();
    QString certificationVersionId = settings.getCertificationVersionId();
    QString certificateType = settings.getCertificateType();

    if (registrationUrl.isEmpty()
            || registrationCode.isEmpty()
            || applicationId.isEmpty()
            || certificationVersionId.isEmpty()
            || certificateType.isEmpty())
    {
        qWarning() << "Onboard error: Missing required data";
        return false;
    }

    qint32 gatewayId = 0;
    switch (m_communicationInterface->getCommunicationType())
    {
        case CommunicationType_MQTT:
            gatewayId = 2;
            break;

        case CommunicationType_HTTP:
            gatewayId = 3;
            break;

        case CommunicationType_NOTSET:
        default:
            break;
    }

    if (gatewayId == 0)
    {
        qWarning() << "Error: Invalid communication interface. No gateway ID found.";
        return false;
    }

    QNetworkRequest request;
    request.setUrl(registrationUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QString auth = "Authorization";
    QString authValue = "Bearer " + registrationCode;
    request.setRawHeader(auth.toUtf8(), authValue.toUtf8());

    QString id = settings.getExternalIdPrefix() + Utils::createUuid();
    QString requestBody = "{\"id\": \"" + id + "\",\"applicationId\": \"" + applicationId + "\",\"certificationVersionId\":\"" + certificationVersionId + "\",\"gatewayId\":\"" + QString::number(gatewayId) + "\",\"certificateType\":\"" + certificateType + "\"}";

    NetworkReply reply = m_communicationInterface->sendMessage(request, requestBody.toUtf8());
    bool success = handleReceivedOnboardReply(reply, id);
    if (success)
    {
        settings.setExternalId(id);
    }

    return success;
}

bool Registration::handleReceivedOnboardReply(const NetworkReply &reply, const QString &certificateFileName)
{

    if (reply.errorCode)
    {
        Utils::printErrorMessageFromReply(reply.data);
        return false;
    }

    QJsonParseError jerror;
    QJsonDocument jdoc = QJsonDocument::fromJson(reply.data, &jerror);

    if ((int)jerror.error != QJsonParseError::NoError)
    {
        qWarning() << "An error occured while parsing the response body";
        qWarning() << reply.data;
        return false;
    }

    QJsonObject response = jdoc.object();

    if (reply.statusCode == HTTPStatusCode_OK_DATA_CREATED)
    {
        //DEBUG: Print onboard response
        //qDebug() << reply.data;

        Settings &settings = Settings::getInstance();

        QString deviceAlternateId = response.value("deviceAlternateId").toString();
        QString capabilityAlternateId = response.value("capabilityAlternateId").toString();
        QString sensorAlternateId = response.value("sensorAlternateId").toString();
        if (deviceAlternateId.isEmpty() || capabilityAlternateId.isEmpty() || sensorAlternateId.isEmpty())
        {
            qWarning() << "Onboard response error: missing ID";
            return false;
        }

        settings.setDeviceAlternateId(deviceAlternateId);
        settings.setCapabilityAlternateId(capabilityAlternateId);
        settings.setSensorAlternateId(sensorAlternateId);

        QJsonObject connectionCriteria = response["connectionCriteria"].toObject();
        if (connectionCriteria.isEmpty())
        {
            qWarning() << "Onboard response error: connection criteria";
            return false;
        }

        QString measures = connectionCriteria.value("measures").toString();
        if (measures.isEmpty())
        {
            qWarning() << "Onboard response error: field \"measures\" not found";
            return false;
        }

        settings.setMeasures(measures);
        QString commands = connectionCriteria.value("commands").toString();
        if (commands.isEmpty())
        {
            qWarning() << "Onboard response error: field \"commands\" not found";
            return false;
        }

        settings.setCommands(commands);

        QString hostUrl = Utils::getHostUrl(measures, commands);
        if (hostUrl.isEmpty())
        {
            qWarning() << "Onboard response error: host url not found";
            return false;
        }

        qDebug() << "Host-URL:" << hostUrl;
        settings.setIotServicesHost(hostUrl);

        QJsonObject authentication = response["authentication"].toObject();
        if (authentication.isEmpty())
        {
            qWarning() << "Onboard response error: authentication";
            return false;
        }

        QString certificateType = authentication.value("type").toString();
        if (certificateType == "PEM")
        {
            settings.setCertificateType(certificateType);

            QJsonValue ssl_pem_secret = authentication.value("secret");
            QJsonValue ssl_certificate = authentication.value("certificate");

            if (ssl_certificate.isUndefined() || ssl_pem_secret.isUndefined())
            {
                qWarning() << "Onboard response error: certificate";
                return false;
            }

            settings.setSslPassphrase(Utils::encodeBase64(ssl_pem_secret.toString().toUtf8()));
            if (!Utils::createCertificateFiles(ssl_certificate.toString(), certificateFileName))
            {
                qDebug() << "Error writing certificate files";
                return false;
            }
        }
        else if (certificateType == "P12")
        {
            settings.setCertificateType(certificateType);

            //TODO
            // Write certificate data to p12 certificate file
        }

        qDebug() << "Registration successful!";
        return true;
    }
    else
    {
        // DEBUG: Print onboard reply
//        qDebug() << "Onboard Reply statusCode: " << QString::number(reply.statusCode);
//        qDebug() << reply.data;
    }

    return false;
}

}
