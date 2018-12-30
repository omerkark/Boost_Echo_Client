// Created by shaulib@wincs.cs.bgu.ac.il on 12/29/18.
#ifndef BOOST_ECHO_CLIENT_ENCODERDECODER_H__
#define BOOST_ECHO_CLIENT_ENCODERDECODER_H__
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include "../include/EncoderDecoder.h"
#include "../include/connectionHandler.h"

using namespace std;

EncoderDecoder::EncoderDecoder(ConnectionHandler &connectionHandler):connectionHandler(connectionHandler),byteMsg(){}


    void EncoderDecoder::decode() {
        char Opcode[2];
        connectionHandler.getBytes(Opcode, 2);

        switch (bytesToShort(Opcode)) {
            case 9: {
                char Post_PM[1];
                connectionHandler.getBytes(Post_PM, 1);
                cout << "NOTIFICATION ";
                if (Post_PM[0] == '0') cout << "PM ";
                else cout << "public";
                string userName = "";
                connectionHandler.getFrameAscii(userName, '\0');
                string content;
                connectionHandler.getFrameAscii(content, '\0');
                cout << userName + " " + content << endl;
            }
                break;

            case 10:{

            }
                break;

            case 11:{
                char opcode[2];
                connectionHandler.getBytes(opcode,2);
                cout << "ERROR "<< bytesToShort(opcode);
            }
                break;
        }


    }


    short EncoderDecoder::bytesToShort(char* bytesArr)
    {
        short result = (short)((bytesArr[0] & 0xff) << 8);
        result += (short)(bytesArr[1] & 0xff);
        return result;
    }

    void EncoderDecoder::shortToBytes(short num, char* bytesArr)
    {
        bytesArr[0] = ((num >> 8) & 0xFF);
        bytesArr[1] = (num & 0xFF);
    }

#endif