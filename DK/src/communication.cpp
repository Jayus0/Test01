//
// Created by Sunt on 2023/8/21.
//

#include "communication.h"
#include "HttpCommunication.h"
#include "UDPCommunication.h"
#include "TCPCommunication.h"

AbstractCommunicationFactory::AbstractCommunicationFactory() 
{

}

AbstractCommunication *AbstractCommunicationFactory::createCommunication(Type type) 
{
    AbstractCommunication* ptr = nullptr;
    switch (type)
    {
        case Type::HTTP:
            ptr = new HttpCommunication();
            break;
        case Type::TCP:
            ptr = new TcpCommunication();
            break;
        case Type::UDP:
            ptr = new UdpCommunication();
            break;
        default:
            break;
    }
    return ptr;
}

AbstractCommunicationFactory::~AbstractCommunicationFactory() 
{

}
