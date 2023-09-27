//
// Created by Sunt on 2023/8/24.
//

#include <iostream>
#include <fstream>
#include "ConfigInstance.h"
#include "dklog.h"

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
    std::string msg;
    // 尝试解析YAML文件
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
    // 读取压力传感器配置数据
    PressureSensorStruct pTemp;
    for (const auto& pressureSensor : config["PressureSensor"]) {
        pTemp.id = pressureSensor["id"].as<int>();
        pTemp.describer = pressureSensor["describer"].as<std::string>();
        pressureVec.push_back(pTemp);
        msg = "pressureSensor - id: " + std::to_string(pTemp.id) + ", describer: " + pTemp.describer;
        DKLogger::getInstance()->writeLog(msg);
    }
    // 读取温度传感器配置数据
    TemperatureSensorStruct tTemp;
    for (const auto& temperatureSensor : config["TemperatureSensor"]) {
        tTemp.id = temperatureSensor["id"].as<int>();
        tTemp.describer = temperatureSensor["describer"].as<std::string>();
        temperatureVec.push_back(tTemp);
        msg = "temperatureSensor - id: " + std::to_string(tTemp.id) + ", describer: " + tTemp.describer ;
        DKLogger::getInstance()->writeLog(msg);
    }
    // 读取振动速度传感器配置数据
    VibrationVelocitySensorStruct vTemp;
    for (const auto& vibrationVelocitySensor : config["VibrationVelocitySensor"]) {
        vTemp.id = vibrationVelocitySensor["id"].as<int>();
        vTemp.describer = vibrationVelocitySensor["describer"].as<std::string>();
        velocityVec.push_back(vTemp);
        std::string msg = "VibrationVelocitySensor - id: " + std::to_string(vTemp.id) + ", describer: " + vTemp.describer;
        DKLogger::getInstance()->writeLog(msg);
    }
    // 读取振动加速度传感器配置数据
    VibrationAccelerationSensorStruct aTemp;
    for (const auto& vibrationAccelerationSensor : config["VibrationAccelerationSensor"]) {
        aTemp.id = vibrationAccelerationSensor["id"].as<int>();
        aTemp.describer = vibrationAccelerationSensor["describer"].as<std::string>();
        std::string msg = "VibrationAccelerationSensor - id: " + std::to_string(aTemp.id) + ", describer: " + aTemp.describer;
        DKLogger::getInstance()->writeLog(msg);
    }
    // 读取位移传感器配置数据
    DisplacementSensorStruct dTemp;
    for (const auto& DisplacementSensor : config["DisplacementSensor"]) {
        dTemp.id = DisplacementSensor["id"].as<int>();
        dTemp.describer = DisplacementSensor["describer"].as<std::string>();
        std::string msg = "DisplacementSensor - id: " + std::to_string(dTemp.id) + ", describer: " + dTemp.describer ;
        DKLogger::getInstance()->writeLog(msg);
    }
    // 读取TDC相位传感器配置数据
    TDCPhaseSensorStruct tdcTemp;
    for (const auto& tdcPhaseSensor : config["TDCPhaseSensor"]) {
        tdcTemp.id = tdcPhaseSensor["id"].as<int>();
        tdcTemp.describer = tdcPhaseSensor["describer"].as<std::string>();
        msg = "TDCPhaseSensor - id: " + std::to_string(tdcTemp.id) + ", describer: " + tdcTemp.describer;
        DKLogger::getInstance()->writeLog(msg);
    }

}

NetInfo ConfigInstance::getNetInfo() {
    return m_netInfo;
}

//SensorInfo ConfigInstance::getSensorInfo() {
//    return m_sensorInfo;
//}
