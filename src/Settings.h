//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef SETTINGS_7DB1692AF68F444F96826528B680B6E3
#define SETTINGS_7DB1692AF68F444F96826528B680B6E3

#include <QObject>
#include "CCIAgrirouter/Globals.h"

namespace CCIAgrirouter
{

class Settings : public QObject
{
    Q_OBJECT
public:
    static Settings& getInstance();

    void setParameters(const SettingsParameters &params);
    void clearSettings();

    QByteArray getSslPassphrase() const;
    void setSslPassphrase(const QByteArray &value);

    QString getSensorAlternateId() const;
    void setSensorAlternateId(const QString &value);

    QString getExternalId() const;
    void setExternalId(const QString &value);

    QString getExternalIdPrefix() const;
    void setExternalIdPrefix(const QString &value);

    QString getIotServicesHost() const;
    void setIotServicesHost(const QString &value);

    QString getDataDir() const;
    void setDataDir(const QString &value);

    QString getApplicationId() const;
    void setApplicationId(const QString &value);

    QString getCertificationVersionId() const;
    void setCertificationVersionId(const QString &value);

    QString getMaiOauthClientId() const;
    void setMaiOauthClientId(const QString &value);

    QString getMaiOauthClientSecret() const;
    void setMaiOauthClientSecret(const QString &value);

    QString getCapabilityAlternateId() const;
    void setCapabilityAlternateId(const QString &value);

    QString getDeviceAlternateId() const;
    void setDeviceAlternateId(const QString &value);

    QString getMeasures() const;
    void setMeasures(const QString &value);

    QString getCommands() const;
    void setCommands(const QString &value);

    QString getRegistrationUrl() const;
    void setRegistrationUrl(const QString &value);

    QString getCertificateType() const;
    void setCertificateType(const QString &value);

    quint32 getPollTryCount() const;
    void setPollTryCount(const quint32 &value);

    quint32 getTimeoutMsecs() const;
    void setTimeoutMsecs(const quint32 &value);

    quint16 getIotServicesPort() const;
    void setIotServicesPort(const quint16 &value);

    QString getTeamSetContextId() const;
    void setTeamSetContextId(const QString &teamSetContextId);

private:
    Settings(QObject* parent = nullptr);

    QByteArray m_sslPassphrase;

    QString m_sensorAlternateId;
    QString m_externalId;
    QString m_externalIdPrefix;
    QString m_iotServicesHost;
    QString m_dataDir;
    QString m_applicationId;
    QString m_certificationVersionId;
    QString m_maiOauthClientId;
    QString m_maiOauthClientSecret;
    QString m_capabilityAlternateId;
    QString m_deviceAlternateId;
    QString m_measures;
    QString m_commands;
    QString m_registrationUrl;
    QString m_certificateType;
    QString m_teamSetContextId;

    quint32 m_pollTryCount = 0;
    quint32 m_timeoutMsecs = 0;

    quint16 m_iotServicesPort = 0;
};

}

#endif//SETTINGS_7DB1692AF68F444F96826528B680B6E3
