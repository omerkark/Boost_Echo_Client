//
// Created by shaulib@wincs.cs.bgu.ac.il on 12/29/18.
#include "connectionHandler.h"
#include "../src/connectionHandler.cpp"
#ifndef BOOST_ECHO_CLIENT_ENCODERDECODER_H
#define BOOST_ECHO_CLIENT_ENCODERDECODER_H
#include <string>
#include <vector>

#endif //BOOST_ECHO_CLIENT_ENCODERDECODER_H
class EncoderDecoder{
public:
    EncoderDecoder(ConnectionHandler &connectionHandler);
private:
    std::vector<char> byteMsg;
    ConnectionHandler &connectionHandler;
};