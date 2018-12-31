//
// Created by shaulib@wincs.cs.bgu.ac.il on 12/31/18.
//

#ifndef BOOST_ECHO_CLIENT_SERVERTOCLIENT_H
#define BOOST_ECHO_CLIENT_SERVERTOCLIENT_H
#include "connectionHandler.h"

class serverToClient{


    serverToClient (ConnectionHandler &connectionHandler);
    short bytesToShort(char* bytesArr);
    void shortToBytes(short num, char* bytesArr);
    void printFunction(std::string Case);
    void decode();
    void run();

private:
    ConnectionHandler &connectionHandler;
    bool terminate;

};

#endif //BOOST_ECHO_CLIENT_SERVERTOCLIENT_H
