//
// Created by Sunt on 2023/8/24.
//

#include "SpeedSensor.h"

SpeedSensor::SpeedSensor() {

}

SpeedSensor::~SpeedSensor() {

}

void SpeedSensor::acquireData() {

}

SpeedSensorFactory::SpeedSensorFactory() {

}

SpeedSensorFactory::~SpeedSensorFactory() {

}

AbstractDataAcquisition *SpeedSensorFactory::createDataAcquisition() {
    AbstractDataAcquisition* ptr = new SpeedSensor();
    return ptr;
}
