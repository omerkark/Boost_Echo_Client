//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/30/18.
//

#ifndef BOOST_ECHO_CLIENT_READFROMKEYBOARD_H
#define BOOST_ECHO_CLIENT_READFROMKEYBOARD_H

#endif //BOOST_ECHO_CLIENT_READFROMKEYBOARD_H
#include <mutex>
#include "connectionHandler.h"

using namespace std;


class readFromKeyBoard{
public:
    readFromKeyBoard (ConnectionHandler &connectionHandler, bool& globalTerminate , std::mutex& mutex);
    short convertStringToshort(std::string s);
    void run();
    void shortToBytes(short num, char* bytesArr);
    string contentToSend(vector<string> words, int index);


    private:
        bool &terminate;
        std::mutex & _mutex;
        ConnectionHandler &connectionHandler;


};