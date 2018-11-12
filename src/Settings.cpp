//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#include "Settings.h"

namespace CCIAgrirouter
{

Settings& Settings::getInstance()
{
    static Settings* s_instance = nullptr;
    if (s_instance == nullptr)
    {
        s_instance = new Settings();
    }

    return *s_instance;
}

Settings::Settings(QObject *parent) : QObject(parent)
{

}

QString Settings::getTeamSetContextId() const
{
    return m_teamSetContextId;
}

void Settings::setTeamSetContextId(const QString &teamSetContextId)
{
    m_teamSetContextId = teamSetContextId;
}

QString Settings::getExternalIdPrefix() const
{
    return m_externalIdPrefix;
}

void Settings::setExternalIdPrefix(const QString &value)
{
    m_externalIdPrefix = value;
}

quint16 Settings::getIotServicesPort() const
{
    return m_iotServicesPort;
}

void Settings::setIotServicesPort(const quint16 &value)
{
    m_iotServicesPort = value;
}

quint32 Settings::getTimeoutMsecs() const
{
    return m_timeoutMsecs;
}

void Settings::setTimeoutMsecs(const quint32 &value)
{
    m_timeoutMsecs = value;
}

quint32 Settings::getPollTryCount() const
{
    return m_pollTryCount;
}

void Settings::setPollTryCount(const quint32 &value)
{
    m_pollTryCount = value;
}

QString Settings::getCertificateType() const
{
    return m_certificateType;
}

void Settings::setCertificateType(const QString &value)
{
    m_certificateType = value;
}

QString Settings::getRegistrationUrl() const
{
    return m_registrationUrl;
}

void Settings::setRegistrationUrl(const QString &value)
{
    m_registrationUrl = value;
}

QString Settings::getCommands() const
{
    return m_commands;
}

void Settings::setCommands(const QString &value)
{
    m_commands = value;
}

QString Settings::getMeasures() const
{
    return m_measures;
}

void Settings::setMeasures(const QString &value)
{
    m_measures = value;
}

QString Settings::getDeviceAlternateId() const
{
    return m_deviceAlternateId;
}

void Settings::setDeviceAlternateId(const QString &value)
{
    m_deviceAlternateId = value;
}

QString Settings::getCapabilityAlternateId() const
{
    return m_capabilityAlternateId;
}

void Settings::setCapabilityAlternateId(const QString &value)
{
    m_capabilityAlternateId = value;
}

QString Settings::getMaiOauthClientSecret() const
{
    return m_maiOauthClientSecret;
}

void Settings::setMaiOauthClientSecret(const QString &value)
{
    m_maiOauthClientSecret = value;
}

QString Settings::getMaiOauthClientId() const
{
    return m_maiOauthClientId;
}

void Settings::setMaiOauthClientId(const QString &value)
{
    m_maiOauthClientId = value;
}

QString Settings::getCertificationVersionId() const
{
    return m_certificationVersionId;
}

void Settings::setCertificationVersionId(const QString &value)
{
    m_certificationVersionId = value;
}

QString Settings::getApplicationId() const
{
    return m_applicationId;
}

void Settings::setApplicationId(const QString &value)
{
    m_applicationId = value;
}

QString Settings::getDataDir() const
{
    return m_dataDir;
}
void Settings::setDataDir(const QString &value)
{
    m_dataDir = value;
}

QString Settings::getIotServicesHost() const
{
    return m_iotServicesHost;
}

void Settings::setIotServicesHost(const QString &value)
{
    m_iotServicesHost = value;
}

QString Settings::getExternalId() const
{
    return m_externalId;
}

void Settings::setExternalId(const QString &value)
{
    m_externalId = value;
}

QString Settings::getSensorAlternateId() const
{
    return m_sensorAlternateId;
}

void Settings::setSensorAlternateId(const QString &value)
{
    m_sensorAlternateId = value;
}

QByteArray Settings::getSslPassphrase() const
{
    return m_sslPassphrase;
}

void Settings::setSslPassphrase(const QByteArray &value)
{
    m_sslPassphrase = value;
}

void Settings::setParameters(const SettingsParameters &params)
{
    m_sslPassphrase = params.sslPassphrase;
    m_sensorAlternateId = params.sensorAlternateId;
    m_externalId = params.externalId;
    m_externalIdPrefix = params.externalIdPrefix;
    m_iotServicesHost = params.iotServicesHost;
    m_dataDir = params.dataDir;
    m_applicationId = params.applicationId;
    m_certificationVersionId = params.certificationVersionId;
    m_maiOauthClientId = params.maiOauthClientId;
    m_maiOauthClientSecret = params.maiOauthClientSecret;
    m_capabilityAlternateId = params.capabilityAlternateId;
    m_deviceAlternateId = params.deviceAlternateId;
    m_measures = params.measures;
    m_commands = params.commands;
    m_registrationUrl = params.registrationUrl;
    m_certificateType = params.certificateType;
    m_teamSetContextId = params.teamSetContextId;
    m_pollTryCount = params.pollTryCount;
    m_timeoutMsecs = params.timeoutMsecs;
    m_iotServicesPort = params.iotServicesPort;
}

void Settings::clearSettings()
{
    m_sslPassphrase.clear();
    m_sensorAlternateId.clear();
    m_externalId.clear();
    m_capabilityAlternateId.clear();
    m_deviceAlternateId.clear();
    m_measures.clear();
    m_commands.clear();
    m_teamSetContextId.clear();
}

}
