//
// Created by Sunt on 2023/8/18.
//

#ifndef DK_DKLOG_H
#define DK_DKLOG_H

#include <string>
#include <mutex>

class DKLogger
{
public:
    static DKLogger * getInstance();
    void writeLog(const std::string& message);
    ~DKLogger();

    DKLogger(const DKLogger& obj) = delete;
    DKLogger& operator=(const DKLogger& obj) = delete;

private:
    std::string getCurrentTime(std::string& currentdata);

    DKLogger()= default;
    static std::mutex m_mutex;
    static DKLogger* instance;


};
#endif //DK_DKLOG_H
