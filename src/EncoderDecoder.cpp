// Created by shaulib@wincs.cs.bgu.ac.il on 12/29/18.
#include "../include/EncoderDecoder.h"
#include "connectionHandler.cpp"
#include "../include/connectionHandler.h"
#ifndef BOOST_ECHO_CLIENT_ENCODERDECODER_H__
#define BOOST_ECHO_CLIENT_ENCODERDECODER_H__
#include <string>
#include <iostream>
#include <boost/asio.hpp>

EncoderDecoder::EncoderDecoder(ConnectionHandler &connectionHandler):connectionHandler(connectionHandler){


}
#endif