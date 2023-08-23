//
// Created by Sunt on 2023/8/21.
//

/*
 * 数据请求模块（来自于硬件）
 *
 * */

#ifndef DK_DATAACQUISITION_H
#define DK_DATAACQUISITION_H

class AbstractDataAcquisition {
public:
    AbstractDataAcquisition(){};

    virtual void acquireData() = 0;

    virtual ~AbstractDataAcquisition(){};
};


class AbstractDataAcquisitionFactory
{
public:
    AbstractDataAcquisitionFactory(){};

    virtual AbstractDataAcquisition* createDataAcquisition() = 0;

    virtual ~AbstractDataAcquisitionFactory(){};
};


#endif //DK_DATAACQUISITION_H
