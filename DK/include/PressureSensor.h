//
// Created by Sunt on 2023/8/24.
//

/*
 * 动态压力传感器
 * */

#ifndef DK_PRESSURESENSOR_H
#define DK_PRESSURESENSOR_H

#include "DataAcquisition.h"


class PressureSensor : public AbstractDataAcquisition{
public:
    PressureSensor();
    ~PressureSensor();

    void acquireData() override;

};


class PressureSensorFactory : public AbstractDataAcquisitionFactory
{
public:
    PressureSensorFactory();
    ~PressureSensorFactory();

    AbstractDataAcquisition* createDataAcquisition() override;

};


#endif //DK_PRESSURESENSOR_H
