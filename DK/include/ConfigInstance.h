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
    int id;
    double pressure;
    std::string describer;
}PressureSensorStruct;

typedef struct
{
    int id;
    double temperature;
    std::string describer;
}TemperatureSensorStruct;

typedef struct
{
    int id;
    double speed;
    std::string describer;
}VibrationVelocitySensorStruct;

typedef struct
{
    int id;
    double vibration;
    std::string describer;
}VibrationAccelerationSensorStruct;

typedef struct
{
    int id;
    double displacement;
    std::string describer;
}DisplacementSensorStruct;

typedef struct
{
    int id;
    double phase;
    std::string describer;
}TDCPhaseSensorStruct;

//typedef struct
//{
//    PressureSensorStruct _pressureSensorInfo;
//    TemperatureSensorStruct _temperatureSensorInfo;
//    VibrationVelocitySensorStruct _vibrationVelocitySensor;
//    VibrationAccelerationSensorStruct _vibrationAccelerationSensorInfo;
//    DisplacementSensorStruct _displacementSensorInfo;
//    TDCPhaseSensorStruct _tdcPhaseSensorInfo;
//}SensorInfo;


class ConfigInstance {
public:
    static ConfigInstance* getInstance();
    ~ConfigInstance();
    ConfigInstance(const ConfigInstance& obj) = delete;
    ConfigInstance& operator=(const ConfigInstance& obj) = delete;

    void loadConfigFile();

    NetInfo getNetInfo();
    //SensorInfo getSensorInfo();

private:
    ConfigInstance() = default;

    static std::mutex m_mutex;
    static ConfigInstance* instance;

    NetInfo m_netInfo;
//    SensorInfo m_sensorInfo;
    std::vector<PressureSensorStruct> pressureVec;
    std::vector<TemperatureSensorStruct> temperatureVec;
    std::vector<VibrationVelocitySensorStruct> velocityVec;
    std::vector<VibrationAccelerationSensorStruct> accelerationVec;
    std::vector<DisplacementSensorStruct> displacementVec;
    std::vector<TDCPhaseSensorStruct> tdcVec;
};


#endif //DK_CONFIGINSTANCE_H
