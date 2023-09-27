//
// Created by Sunt on 2023/8/21.
//

#include <sys/socket.h>
#include <iostream>

#include <sys/shm.h>
#include <sys/select.h>
#include <stdlib.h>
#include <iostream>
#include "UDPCommunication.h"
#include "dklog.h"
#include "ConfigInstance.h"


UdpCommunication::UdpCommunication() {
    std::string msg;
    port = ConfigInstance::getInstance()->getNetInfo()._udpInfo._port;

    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1)
    {
        msg = "Error creating UDP socket.";
        std::cerr<<msg<<std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        msg = "Error binding TCP socket.";
        std::cerr<<msg<<std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }
}

UdpCommunication::~UdpCommunication() {

}

void UdpCommunication::sendData() {
    //to do ...
    //sendto();
}

void UdpCommunication::startListening() {
    std::string msg;

    /*listen*/
    int queue = 20;
    if (listen(socket_fd, queue) == -1)
    {
        msg = "Error TCP listening.";
        std::cerr<<msg<<std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }
    std::cout<<"Listening for incoming TCP connections..."<<std::endl;

    while(true)
    {
        float data = 0.0;
        socklen_t addr_len = sizeof(client_address);

        int client_socket = accept(socket_fd, NULL, NULL);
        if (client_socket == -1)
        {
            msg = "Error accepting TCP client connection.";
            DKLogger::getInstance()->writeLog(msg);
            continue;
        }
    }
}

UdpCommunicationFactory::UdpCommunicationFactory() {

}

UdpCommunicationFactory::~UdpCommunicationFactory() {

}

AbstractCommunication *UdpCommunicationFactory::createCommunication() {
    return new UdpCommunication;
}
