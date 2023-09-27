//
// Created by Sunt on 2023/8/21.
//
#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <sys/shm.h>
#include <sys/select.h>
#include <cstdlib>
#include "TCPCommunication.h"
#include "dklog.h"
#include "ConfigInstance.h"

void TcpCommunication::sendData() {
//    socklen_t addr_len = sizeof (client_addr);

    //to do ...
    //sendto();
}

TcpCommunication::TcpCommunication() {
    port = ConfigInstance::getInstance()->getNetInfo()._tcpInfo._port;

    std::string msg;

    /*创建socket*/
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        msg = "Error creating socket";
        std::cerr<<msg<<std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }

    server_socket.sin_family = AF_INET;
    server_socket.sin_port = htons(port);
    server_socket.sin_addr.s_addr = htonl(INADDR_ANY);

    /*bind*/
    if (bind(socket_fd, (struct sockaddr*)& server_socket, sizeof(server_socket)) == -1)
    {
        msg = "TCP bind Fail";
        std::cerr<<msg<<std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }
}

TcpCommunication::~TcpCommunication() {

}


void TcpCommunication::startListening() {
    std::string msg;
    std::cout<<"listening"<<std::endl;
    /*listen*/
    int queue = 20;
    if (listen(socket_fd, queue) == -1)
    {
        msg = "TCP listen Fail";
        std::cerr<<msg<<std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }

    std::cout<<"Listening for incoming connections..."<<std::endl;

    /*connect*/
    socklen_t length = sizeof (client_addr);
    int conn = accept(socket_fd, (struct sockaddr*)&client_addr, &length);
    if (conn < 0)
    {
        msg = "TCP connect Fail.";
        std::cerr<<msg<<std::endl;
        DKLogger::getInstance()->writeLog(msg);
        exit(1);
    }

    //create a thread
    std::thread client_thread(&TcpCommunication::handleTCPClient, this, conn);
    client_thread.detach();

    while (true)
    {
        /*把可读文件描述分的集合清空*/
        FD_ZERO(&rfds);
        /*把标准输入的文件描述符加入集合中*/
        FD_SET(0, &rfds);
        maxfd = 0;
        /*把当前连接的文件描述符加入到集合中*/
        FD_SET(conn, &rfds);
        /*找出文件描述符集合中最大的文件描述符*/
        if (maxfd < conn)
            maxfd = conn;
        /*设置超时时间*/
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        retval = select(maxfd + 1, &rfds, NULL, NULL, &tv);
        if (retval == -1)
        {
            std::cerr<<"select error, client exit"<<std::endl;
            break;
        }
        else if (retval == 0)
        {
            std::cout<<"The server has no input information, and the client has no input information."<<std::endl;
            continue;
        }
        else
        {
            /*client send data*/
            if (FD_ISSET(conn, &rfds))
            {
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));
                int len = recv(conn, buffer, sizeof(buffer), 0);
                if (strcmp(buffer, "exit\n") == 0) break;
                std::cout<<"buffer: "<<buffer<<std::endl;

                //send(conn, buffer, len, 0); //把数据回发给客户端
            }
            /*send data to client*/
            if (FD_ISSET(0, &rfds))
            {
                char buf[1024] = "hello dk";
                send(conn, buf, sizeof(buf), 0);
            }
        }
    }
}

void TcpCommunication::handleTCPClient(int client_socket) {
    while(true)
    {
        //to do...
        float data = 0.0;

        ssize_t recv_len = recv(client_socket, &data, sizeof(data), 0);
        if (recv_len == -1)
        {
            std::cerr<<"Error receiving TCP data"<<std::endl;
            continue;
        }
    }
}


AbstractCommunication *TcpCommunicationFactory::createCommunication() {
    return new TcpCommunication;
}

TcpCommunicationFactory::TcpCommunicationFactory() {

}

TcpCommunicationFactory::~TcpCommunicationFactory() {

}
