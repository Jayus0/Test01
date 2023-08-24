//
// Created by Sunt on 2023/8/24.
//

/*
 * 震动加速度传感器
 * */

#ifndef DK_VIBRATIONACCELERATIONSENSOR_H
#define DK_VIBRATIONACCELERATIONSENSOR_H

#include "DataAcquisition.h"


class VibrationAccelerationSensor : public AbstractDataAcquisition{
public:
    VibrationAccelerationSensor();
    ~VibrationAccelerationSensor();

    void acquireData() override;

};

class VibrationAccelerationSensorFactory : public AbstractDataAcquisitionFactory
{
public:
    VibrationAccelerationSensorFactory();
    ~VibrationAccelerationSensorFactory();

    AbstractDataAcquisition* createDataAcquisition() override;
};


#endif //DK_VIBRATIONACCELERATIONSENSOR_H
