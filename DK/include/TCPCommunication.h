//
// Created by Sunt on 2023/8/21.
//

#ifndef DK_TCPCOMMUNICATION_H
#define DK_TCPCOMMUNICATION_H

#include "communication.h"

class TcpCommunication : public AbstractCommunication{
public:
    TcpCommunication();
    ~TcpCommunication();

    void sendData() override;

};


#endif //DK_TCPCOMMUNICATION_H
