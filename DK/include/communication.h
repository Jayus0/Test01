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


enum class Type:char{HTTP, UDP, TCP};

class AbstractCommunication
{
public:
    AbstractCommunication(){};

    virtual void sendData() = 0;

    virtual  ~AbstractCommunication(){};
};

class AbstractCommunicationFactory
{
public:
    AbstractCommunicationFactory();

    AbstractCommunication* createCommunication(Type type);

    ~AbstractCommunicationFactory();
};

#endif //DK_COMMUNICATION_H
