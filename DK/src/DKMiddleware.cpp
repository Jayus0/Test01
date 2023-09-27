//
// Created by Sunt on 2023/9/22.
//

#include "DKMiddleware.h"
#include <iostream>

DKMiddleware::DKMiddleware(AbstractCommunication* obj) {
    this->comm = obj;
}

DKMiddleware::~DKMiddleware() {

}

void DKMiddleware::startListen() {

    comm->startListening();
}

void DKMiddleware::sendDataToClient() {
    comm->sendData();
}
