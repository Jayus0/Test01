//
// Created by Sunt on 2023/8/21.
//

#ifndef DK_HTTPCOMMUNICATION_H
#define DK_HTTPCOMMUNICATION_H

#include "communication.h"

class HttpCommunication : public AbstractCommunication{
public:
    HttpCommunication();
    ~HttpCommunication();

    void sendData() override;
};


#endif //DK_HTTPCOMMUNICATION_H
