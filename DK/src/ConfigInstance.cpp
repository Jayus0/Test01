//
// Created by Sunt on 2023/8/24.
//

#include <iostream>
#include "ConfigInstance.h"

ConfigInstance* ConfigInstance::instance = nullptr;
std::mutex ConfigInstance::m_mutex;

ConfigInstance *ConfigInstance::getInstance() {
    if (!instance){
        std::lock_guard<std::mutex> lock(m_mutex);
        if (!instance)
            instance = new ConfigInstance;
    }
    return instance;
}

ConfigInstance::~ConfigInstance() {

}

void ConfigInstance::loadConfigFile() {
    YAML::Node config = YAML::LoadFile("./config/network.yaml");

    if (config["netType"])
        m_netInfo._netType = config["netType"].as<int>();
    if (config["HTTP"])
    {
        if (config["HTTP"]["url"])
            m_netInfo._httpInfo._url = config["HTTP"]["url"].as<std::string>();
    }
    if (config["UDP"])
    {
        if (config["UDP"]["ip"])
            m_netInfo._udpInfo._ip = config["UDP"]["ip"].as<std::string>();
        if (config["UDP"]["port"])
            m_netInfo._udpInfo._port = config["UDP"]["port"].as<int>();
    }
    if (config["TCP"])
    {
        if (config["TCP"]["ip"])
            m_netInfo._tcpInfo._ip = config["UDP"]["ip"].as<std::string>();
        if (config["TCP"]["port"])
            m_netInfo._tcpInfo._port = config["UDP"]["port"].as<int>();
    }

    config = YAML::LoadFile("./config/sensor.yaml");
    if (config["PressureSensor"])
    {
        if (config["PressureSensor"]["number"])
            m_sensorInfo._pressureSensorInfo.number = config["PressureSensor"]["number"].as<int>();
        if (config["PressureSensor"]["describer"])
            m_sensorInfo._pressureSensorInfo.describer = config["PressureSensor"]["describer"].as<std::string>();
    }
    if (config["SpeedSensor"])
    {
        if (config["SpeedSensor"]["number"])
            m_sensorInfo._speedSensorInfo.number = config["SpeedSensor"]["number"].as<int>();
        if (config["SpeedSensor"]["describer"])
            m_sensorInfo._speedSensorInfo.describer = config["SpeedSensor"]["describer"].as<std::string>();
    }
    if (config["VibrationAccelerationSensor"])
    {
        if (config["VibrationAccelerationSensor"]["number"])
            m_sensorInfo._vibrationAccelerationSensorInfo.number = config["VibrationAccelerationSensor"]["number"].as<int>();
        if (config["VibrationAccelerationSensor"]["describer"])
            m_sensorInfo._vibrationAccelerationSensorInfo.describer = config["VibrationAccelerationSensor"]["describer"].as<std::string>();
    }
    if (config["VibrationSpeedSensor"])
    {
        if (config["VibrationSpeedSensor"]["number"])
            m_sensorInfo._vibrationSpeedSensorInfo.number = config["VibrationSpeedSensor"]["number"].as<int>();
        if (config["VibrationSpeedSensor"]["describer"])
            m_sensorInfo._vibrationSpeedSensorInfo.describer = config["VibrationSpeedSensor"]["describer"].as<std::string>();
    }
    if (config["EddyCurrentDisplacementSensor"])
    {
        if (config["EddyCurrentDisplacementSensor"]["number"])
            m_sensorInfo._eddyCurrentDisplacementSensorInfo.number = config["EddyCurrentDisplacementSensor"]["number"].as<int>();
        if (config["EddyCurrentDisplacementSensor"]["describer"])
            m_sensorInfo._eddyCurrentDisplacementSensorInfo.describer = config["EddyCurrentDisplacementSensor"]["describer"].as<std::string>();
    }

}

NetInfo ConfigInstance::getNetInfo() {
    return m_netInfo;
}

SensorInfo ConfigInstance::getSensorInfo() {
    return m_sensorInfo;
}
