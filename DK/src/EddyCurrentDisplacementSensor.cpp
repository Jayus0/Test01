//
// Created by Sunt on 2023/8/24.
//

#include "EddyCurrentDisplacementSensor.h"

EddyCurrentDisplacementSensor::EddyCurrentDisplacementSensor() {

}

EddyCurrentDisplacementSensor::~EddyCurrentDisplacementSensor() {

}

void EddyCurrentDisplacementSensor::acquireData() {

}

EddyCurrentDisplacementSensorFactory::EddyCurrentDisplacementSensorFactory() {

}

EddyCurrentDisplacementSensorFactory::~EddyCurrentDisplacementSensorFactory() {

}

AbstractDataAcquisition *EddyCurrentDisplacementSensorFactory::createDataAcquisition() {
    AbstractDataAcquisition* ptr = new EddyCurrentDisplacementSensor();
    return ptr;
}
