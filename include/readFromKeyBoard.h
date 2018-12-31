//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/30/18.
//

#ifndef BOOST_ECHO_CLIENT_READFROMKEYBOARD_H
#define BOOST_ECHO_CLIENT_READFROMKEYBOARD_H

#endif //BOOST_ECHO_CLIENT_READFROMKEYBOARD_H
using namespace std;
#include <mutex>

enum CommandType{
    REGISTER, LOGIN, LOGOUT, FOLLOW, POST, PM, USERLIST, STAT
};

class readFromKeyBoard{

    private:
        bool &terminate;
        std::mutex & _mutex;

    public:
        readFromKeyBoard (bool& globalTerminate , std::mutex& mutex);
        CommandType convertStringToEnum(std::string s);
        void run();
};