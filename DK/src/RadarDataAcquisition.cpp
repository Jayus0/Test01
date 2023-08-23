//
// Created by Sunt on 2023/8/21.
//

#include "RadarDataAcquisition.h"

RadarDataAcquisition::RadarDataAcquisition() {

}

void RadarDataAcquisition::acquireData() {

}

RadarDataAcquisition::~RadarDataAcquisition() {

}





RadarDataAcquisitionFactory::RadarDataAcquisitionFactory() {

}

RadarDataAcquisitionFactory::~RadarDataAcquisitionFactory() {

}

AbstractDataAcquisition *RadarDataAcquisitionFactory::createDataAcquisition() {
    AbstractDataAcquisition* ptr = nullptr;
    ptr = new RadarDataAcquisition();
    return ptr;
}
