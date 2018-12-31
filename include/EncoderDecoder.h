//
// Created by shaulib@wincs.cs.bgu.ac.il on 12/29/18.

#ifndef BOOST_ECHO_CLIENT_ENCODERDECODER_H
#define BOOST_ECHO_CLIENT_ENCODERDECODER_H
#include <string>
#include <vector>
#include "connectionHandler.h"

#endif //BOOST_ECHO_CLIENT_ENCODERDECODER_H
class EncoderDecoder{
public:
    EncoderDecoder(ConnectionHandler &connectionHandler);
    short bytesToShort(char* bytesArr);
    void shortToBytes(short num, char* bytesArr);
    void printFunction(std::string Case);
    void decode();


private:
    std::vector<char> byteMsg;
    ConnectionHandler &connectionHandler;

};