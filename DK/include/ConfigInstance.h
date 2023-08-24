//
// Created by Sunt on 2023/8/24.
//

/*
 * 读取配置文件模块
 * */

#ifndef DK_CONFIGINSTANCE_H
#define DK_CONFIGINSTANCE_H

#include <mutex>
#include <string>
#include "yaml-cpp/yaml.h"


/*
 * network.yaml
 * */
typedef struct
{
    std::string _url;
}HttpStruct;
[[maybe_unused]] typedef struct
{
    std::string _ip;
    int _port;
}CommunicatStruct;
typedef struct
{
    int _netType;
    HttpStruct _httpInfo;
    CommunicatStruct _udpInfo;
    CommunicatStruct _tcpInfo;
}NetInfo;


/*
 * sensor.yaml
 * */
typedef struct
{
    int number;
    std::string describer;
}PressureSensorStruct;
typedef struct
{
    int number;
    std::string describer;
}SpeedSensorStruct;
typedef struct
{
    int number;
    std::string describer;
}VibrationAccelerationSensorStruct;
typedef struct
{
    int number;
    std::string describer;
}VibrationSpeedSensorStruct;
typedef struct
{
    int number;
    std::string describer;
}EddyCurrentDisplacementSensorStruct;
typedef struct
{
    PressureSensorStruct _pressureSensorInfo;
    SpeedSensorStruct _speedSensorInfo;
    VibrationAccelerationSensorStruct _vibrationAccelerationSensorInfo;
    VibrationSpeedSensorStruct _vibrationSpeedSensorInfo;
    EddyCurrentDisplacementSensorStruct _eddyCurrentDisplacementSensorInfo;
}SensorInfo;


class ConfigInstance {
public:
    static ConfigInstance* getInstance();
    ~ConfigInstance();
    ConfigInstance(const ConfigInstance& obj) = delete;
    ConfigInstance& operator=(const ConfigInstance& obj) = delete;

    void loadConfigFile();

    NetInfo getNetInfo();
    SensorInfo getSensorInfo();

private:
    ConfigInstance() = default;

    static std::mutex m_mutex;
    static ConfigInstance* instance;

    NetInfo m_netInfo;
    SensorInfo m_sensorInfo;
};


#endif //DK_CONFIGINSTANCE_H
