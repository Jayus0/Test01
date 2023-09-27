//
// Created by Sunt on 2023/8/21.
//

#ifndef DK_TCPCOMMUNICATION_H
#define DK_TCPCOMMUNICATION_H

#include <netinet/in.h>

#include "communication.h"
#include <stdio.h>

class TcpCommunication : public AbstractCommunication{
public:
    TcpCommunication();
    ~TcpCommunication();

    void startListening() override;
    void sendData() override;

private:
    void handleTCPClient(int client_socket);

private:
    int port;
    int socket_fd;

    fd_set rfds;
    struct timeval tv;
    int retval;
    int maxfd;

    struct sockaddr_in client_addr;
    struct sockaddr_in server_socket;

};

class TcpCommunicationFactory : public AbstractCommunicationFactory
{
public:
    TcpCommunicationFactory();
    ~TcpCommunicationFactory();

    AbstractCommunication* createCommunication() override;


};


#endif //DK_TCPCOMMUNICATION_H
