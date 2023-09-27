//
// Created by Sunt on 2023/8/21.
//

/*
 * 数据通信模块（主要与web端或其他进行数据传递）
 * */

#ifndef DK_COMMUNICATION_H
#define DK_COMMUNICATION_H

#include <string>
#include "yaml-cpp/yaml.h"


class AbstractCommunication
{
public:
    AbstractCommunication(){};

    virtual void sendData() = 0;
    virtual void startListening() = 0;

    virtual  ~AbstractCommunication(){};
};

class AbstractCommunicationFactory
{
public:
    AbstractCommunicationFactory(){};

    virtual AbstractCommunication* createCommunication() = 0;

    virtual ~AbstractCommunicationFactory(){};
};

#endif //DK_COMMUNICATION_H
