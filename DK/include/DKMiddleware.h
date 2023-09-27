//
// Created by Sunt on 2023/9/22.
//

#ifndef DK_DKMIDDLEWARE_H
#define DK_DKMIDDLEWARE_H

#include "communication.h"


class DKMiddleware {
public:
    DKMiddleware(AbstractCommunication* obj);
    ~DKMiddleware();

    void startListen();
    void sendDataToClient();

private:
    AbstractCommunication* comm;

};


#endif //DK_DKMIDDLEWARE_H
