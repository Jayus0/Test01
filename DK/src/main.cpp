#include <iostream>
#include "dklog.h"
#include "communication.h"
//#include "DataAcquisition.h"
#include "ConfigInstance.h"
#include "TCPCommunication.h"
#include "UDPCommunication.h"
#include "DKMiddleware.h"
#include <chrono>
#include <thread>

int main() {

    std::cout<<"Hello DK"<<std::endl;
    DKLogger::getInstance()->writeLog("Hello DK////");
    ConfigInstance::getInstance()->loadConfigFile();
    int netType = ConfigInstance::getInstance()->getNetInfo()._netType;
    std::string msg;
    AbstractCommunicationFactory* factory;
    AbstractCommunication* obj;
    if (netType == 0)
    {
        msg = "No connect.";
        DKLogger::getInstance()->writeLog(msg);
        return 0;
    }
    else if (netType == 2) {
        msg = "UDP connect.";
        std::cout << msg << std::endl;
        DKLogger::getInstance()->writeLog(msg);
        factory = new UdpCommunicationFactory;
        obj = factory->createCommunication();
    }
    else if (netType == 3)
    {
        msg = "TCP connect.";
        std::cout << msg << std::endl;
        DKLogger::getInstance()->writeLog(msg);
        factory = new TcpCommunicationFactory;
        obj = factory->createCommunication();
    }
    else
    {
        msg = "Error type to connect -- netType: " + std::to_string(netType);
        std::cout << msg << std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }


    auto middleware = new DKMiddleware(obj);
    middleware->startListen();

    while(true)
    {
        //获取传感器数据

        //处理数据

        //发送数据

        std::cout<<"111"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        break;
    }

    delete factory;
    delete obj;
    delete middleware;

    return 0;
}
