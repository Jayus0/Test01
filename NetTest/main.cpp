#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <chrono>

int main() {
    int socket_fd, n;
    struct sockaddr_in serv_addr;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        std::cerr<<"Error create socket: "<<socket_fd<<std::endl;
        return 0;
    }

    memset(&serv_addr, 0, sizeof (serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6666);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socket_fd, (struct sockaddr*)&serv_addr, sizeof (serv_addr)) < 0)
    {
        std::cerr<<"Error connect: "<<std::endl;
        return 0;
    }

    char sendLine[1024] = "client";
    char recvLine[1024];

    while (true)
    {
        send(socket_fd, sendLine, sizeof (sendLine), 0);
        //std::this_thread::sleep_for(std::chrono::microseconds(1000));
//        recv(socket_fd, recvLine, sizeof (recvLine), 0);
//        std::cout<<"recv: "<<recvLine<<std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

//        memset(sendLine, 0, sizeof (sendLine));
        memset(recvLine, 0, sizeof (recvLine));
    }


    return 0;
}
