//
// Created by Sunt on 2023/8/21.
//

#ifndef DK_UDPCOMMUNICATION_H
#define DK_UDPCOMMUNICATION_H

#include "communication.h"

class UdpCommunication : public AbstractCommunication{
public:
    UdpCommunication();
    ~UdpCommunication();

    void sendData() override;

};


#endif //DK_UDPCOMMUNICATION_H
