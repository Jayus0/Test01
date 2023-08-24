#include <iostream>
#include "dklog.h"
#include "communication.h"
#include "DataAcquisition.h"
#include "ConfigInstance.h"

int main() {

    std::cout<<"Hello DK"<<std::endl;
    DKLogger::getInstance()->writeLog("Hello DK////");
//    ConfigInstance::getInstance()->loadConfigFile();
    return 0;
}
