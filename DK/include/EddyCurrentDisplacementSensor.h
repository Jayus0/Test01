//
// Created by Sunt on 2023/8/24.
//

/*
 * 电涡流位移传感器
 * */

#ifndef DK_EDDYCURRENTDISPLACEMENTSENSOR_H
#define DK_EDDYCURRENTDISPLACEMENTSENSOR_H

#include "DataAcquisition.h"


class EddyCurrentDisplacementSensor : public AbstractDataAcquisition{
public:
    EddyCurrentDisplacementSensor();
    ~EddyCurrentDisplacementSensor();

    void acquireData() override;

};


class EddyCurrentDisplacementSensorFactory : public AbstractDataAcquisitionFactory
{
public:
    EddyCurrentDisplacementSensorFactory();
    ~EddyCurrentDisplacementSensorFactory();

    AbstractDataAcquisition* createDataAcquisition() override;
};


#endif //DK_EDDYCURRENTDISPLACEMENTSENSOR_H
