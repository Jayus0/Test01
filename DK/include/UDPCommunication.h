//
// Created by Sunt on 2023/8/21.
//

#ifndef DK_UDPCOMMUNICATION_H
#define DK_UDPCOMMUNICATION_H

#include <netinet/in.h>
#include "communication.h"

class UdpCommunication : public AbstractCommunication{
public:
    UdpCommunication();
    ~UdpCommunication();

    void startListening() override;

    void sendData() override;

private:
    int socket_fd;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    int port;

};

class UdpCommunicationFactory : public AbstractCommunicationFactory
{
public:
    UdpCommunicationFactory();
    ~UdpCommunicationFactory();

    AbstractCommunication* createCommunication() override;
};


#endif //DK_UDPCOMMUNICATION_H
