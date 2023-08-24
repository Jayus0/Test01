//
// Created by Sunt on 2023/8/24.
//

#include "VibrationSpeedSensor.h"

VibrationSpeedSensor::VibrationSpeedSensor() {

}

VibrationSpeedSensor::~VibrationSpeedSensor() {

}

void VibrationSpeedSensor::acquireData() {

}



VibrationSpeedSensorFactory::VibrationSpeedSensorFactory() {

}

VibrationSpeedSensorFactory::~VibrationSpeedSensorFactory() {

}

AbstractDataAcquisition *VibrationSpeedSensorFactory::createDataAcquisition() {
    AbstractDataAcquisition* ptr = new VibrationSpeedSensor();
    return ptr;
}
