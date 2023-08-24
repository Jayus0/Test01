//
// Created by Sunt on 2023/8/24.
//

/*
 * 振动速度传感器
 * */

#ifndef DK_VIBRATIONSPEEDSENSOR_H
#define DK_VIBRATIONSPEEDSENSOR_H

#include "DataAcquisition.h"


class VibrationSpeedSensor : public AbstractDataAcquisition{
public:
    VibrationSpeedSensor();
    ~VibrationSpeedSensor();

    void acquireData() override;
};


class VibrationSpeedSensorFactory : public AbstractDataAcquisitionFactory
{
public:
    VibrationSpeedSensorFactory();
    ~VibrationSpeedSensorFactory();

    AbstractDataAcquisition* createDataAcquisition() override;
};

#endif //DK_VIBRATIONSPEEDSENSOR_H
