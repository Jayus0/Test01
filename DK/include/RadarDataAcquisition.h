//
// Created by Sunt on 2023/8/21.
//

#ifndef DK_RADARDATAACQUISITION_H
#define DK_RADARDATAACQUISITION_H

#include "DataAcquisition.h"


class RadarDataAcquisition : public AbstractDataAcquisition
{
public:
    RadarDataAcquisition();
    ~RadarDataAcquisition();

    void acquireData() override;
};


class RadarDataAcquisitionFactory : public AbstractDataAcquisitionFactory
{
public:
    RadarDataAcquisitionFactory();
    ~RadarDataAcquisitionFactory();

    AbstractDataAcquisition * createDataAcquisition() override;

};


#endif //DK_RADARDATAACQUISITION_H
