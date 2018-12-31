//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/30/18.
//

#ifndef BOOST_ECHO_CLIENT_READFROMKEYBOARD_H
#define BOOST_ECHO_CLIENT_READFROMKEYBOARD_H

#endif //BOOST_ECHO_CLIENT_READFROMKEYBOARD_H
#include <mutex>
#include "connectionHandler.h"

using namespace std;

enum CommandType{
    REGISTER, LOGIN, LOGOUT, FOLLOW, POST, PM, USERLIST, STAT
};

class readFromKeyBoard{
public:
    readFromKeyBoard (ConnectionHandler &connectionHandler, bool& globalTerminate , std::mutex& mutex);
    CommandType convertStringToEnum(std::string s);
    void run();


    private:
        bool &terminate;
        std::mutex & _mutex;
        ConnectionHandler &connectionHandler;


};