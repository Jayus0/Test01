//
// Created by Sunt on 2023/8/24.
//

#include "VibrationAccelerationSensor.h"

VibrationAccelerationSensor::VibrationAccelerationSensor() {

}

VibrationAccelerationSensor::~VibrationAccelerationSensor() {

}

void VibrationAccelerationSensor::acquireData() {

}

VibrationAccelerationSensorFactory::VibrationAccelerationSensorFactory() {

}

VibrationAccelerationSensorFactory::~VibrationAccelerationSensorFactory() {

}

AbstractDataAcquisition *VibrationAccelerationSensorFactory::createDataAcquisition() {
    AbstractDataAcquisition* ptr = new VibrationAccelerationSensor();
    return ptr;
}
