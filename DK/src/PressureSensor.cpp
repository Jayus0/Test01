//
// Created by Sunt on 2023/8/24.
//

#include "PressureSensor.h"

PressureSensor::PressureSensor() {

}

PressureSensor::~PressureSensor() {

}

void PressureSensor::acquireData() {

}

PressureSensorFactory::PressureSensorFactory() {

}

PressureSensorFactory::~PressureSensorFactory() {

}

AbstractDataAcquisition *PressureSensorFactory::createDataAcquisition() {
    AbstractDataAcquisition* ptr = new PressureSensor();

    return ptr;
}
