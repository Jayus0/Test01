//
// Created by Sunt on 2023/8/18.
//
#include <ctime>
#include <iostream>
#include <fstream>
#include "dklog.h"

DKLogger* DKLogger::instance = nullptr;
std::mutex DKLogger::m_mutex;

void DKLogger::writeLog(const std::string &message)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string currentData;
    std::string currentTime = getCurrentTime(currentData);

    std::ofstream logFile("./" + currentData + ".log", std::ios::app);
    if (logFile.is_open()){
        logFile << "[" << currentTime << "] " << message << std::endl;
        logFile.close();
    } else{
        std::cerr<<"app.log open error!!!"<<std::endl;
    }
}


DKLogger *DKLogger::getInstance()
{
    if (!instance){
        std::lock_guard<std::mutex> lock(m_mutex);
        if (!instance){
            instance = new DKLogger;
        }
    }
    return instance;
}

DKLogger::~DKLogger()
= default;

std::string DKLogger::getCurrentTime(std::string &currentdata)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    char timeBuffer[80];
    char dataBuffer[80];
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now_time));
    strftime(dataBuffer, sizeof(dataBuffer), "%Y-%m-%d", std::localtime(&now_time));
    currentdata = dataBuffer;
    return timeBuffer;
}

