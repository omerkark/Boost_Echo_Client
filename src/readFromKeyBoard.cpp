//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/30/18.
//
#include <boost/algorithm/string.hpp>
#include <readFromKeyBoard.h>
#include <vector>
#include <iostream>

using namespace std;


    readFromKeyBoard::readFromKeyBoard(ConnectionHandler *connectionHandler, bool *globalLogin): connectionHandler(connectionHandler) , login(globalLogin){};

    short readFromKeyBoard::convertStringToshort(std::string s) {
        if (s == "REGISTER")
            return ((short)1);
        if (s == "LOGIN")
            return ((short)2);
        if (s == "LOGOUT")
            return ((short)3);
        if (s == "FOLLOW")
            return ((short)4);
        if (s == "POST")
            return ((short)5);
        if (s == "PM")
            return ((short)6);
        if (s == "USERLIST")
            return ((short)7);

        return ((short)8);
    }

        void readFromKeyBoard::shortToBytes(short num, char* bytesArr)
        {
            bytesArr[0] = ((num >> 8) & 0xFF);
            bytesArr[1] = (num & 0xFF);
        }

       void readFromKeyBoard::run(){
            while(!terminate){
                string line;
                vector<string> words;
                vector<char> bytesForServer;
                getline(cin , line);
                boost::split(words, line ,boost::is_any_of(" "));
                short opcode = convertStringToshort(words[0]);
                char opcodeArr[2];
                shortToBytes(opcode, opcodeArr);
                connectionHandler.sendBytes(opcodeArr, 2);

                switch (opcode){
                    case 1:
                    case 2:{
                        connectionHandler->sendLine(words[1]);
                        connectionHandler->sendLine(words[2]);
                    }
                    case 3:{
                        if((*login))
                           terminate = true;
                    }
                        break;
                    case 4:{
                        char follow [1];
                        follow[0] = ((char)(std::stoi(words[1])));
                        connectionHandler->sendBytes(follow, 1);
                        char numOfusers[2];
                        shortToBytes(((short)(std::stoi(words[2]))), numOfusers);
                        connectionHandler->sendBytes(numOfusers, 2);
                        for(unsigned int i =3 ; i <words.size(); i++){
                            connectionHandler->sendLine(words[i]);
                        }
                    }
                        break;
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~POST~~~~~~~~~~~~~~~~~~~~~~~
                    case 5:{
                        string content = contentToSend(words , 1);
                        connectionHandler->sendLine(content);
                    }
                        break;
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PM~~~~~~~~~~~~~~~~~~~~~~~
                    case 6:{
                        connectionHandler->sendLine(words[1]);
                        string content = contentToSend(words, 2);

                    }
                        break;
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~USER-LIST~~~~~~~~~~~~~~~~~~~~~~~
                    case 7:{}
                        break;
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STAT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    case 8:{
                        connectionHandler->sendLine(words[1]);                    }
                }
                break;
            }
        }

    string contentToSend(vector<string> words , int index){
        string content;
        for(unsigned int i =index; i < words.size(); i++ ){
            content += words[i] + " ";
        }
        return content;
    }


