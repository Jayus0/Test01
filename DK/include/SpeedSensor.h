//
// Created by Sunt on 2023/8/24.
//

/*
 * 转速/键相传感器
 * */

#ifndef DK_SPEEDSENSOR_H
#define DK_SPEEDSENSOR_H

#include "DataAcquisition.h"


class SpeedSensor : public AbstractDataAcquisition{

public:
    SpeedSensor();
    ~SpeedSensor();

    void acquireData() override;

};


class SpeedSensorFactory : public AbstractDataAcquisitionFactory
{
public:
    SpeedSensorFactory();
    ~SpeedSensorFactory();

    AbstractDataAcquisition* createDataAcquisition() override;
};


#endif //DK_SPEEDSENSOR_H
