//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/31/18.
//
#include <boost/asio/ip/tcp.hpp>
#include <stdlib.h>
#include <iostream>
#include <connectionHandler.h>
#include <boost/algorithm/string.hpp>
#include <readFromKeyBoard.h>
#include <serverToClient.h>
#include <thread>
using namespace std;

int main (int argc, char *argv[]) {

    bool * login = new bool(false);


    ConnectionHandler *connectionHandler=new ConnectionHandler (argv[1] , atoi(argv[2]));

    if (!connectionHandler->connect()) {
        std::cerr << "Cannot connect to " << argv[1] << ":" << atoi(argv[2]) << std::endl;
        return 1;
    }

    readFromKeyBoard reader (connectionHandler, login);
    serverToClient serverToClient1(connectionHandler , login);

    thread keyBoard(&readFromKeyBoard::run, &reader);
    thread server2Client(&serverToClient::run, &serverToClient1);

    server2Client.join();
    keyBoard.join();


    delete login;
    delete connectionHandler;
}