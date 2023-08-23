#include <iostream>
#include "dklog.h"
#include "communication.h"
#include "DataAcquisition.h"

int main() {

    std::cout<<"Hello DK"<<std::endl;
    DKLogger::getInstance()->writeLog("Hello DK////");
    return 0;
}
