//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/30/18.
//
#include <boost/algorithm/string.hpp>
#include <readFromKeyBoard.h>
#include <EncoderDecoder.h>
using namespace std;


    readFromKeyBoard::readFromKeyBoard (bool& globalTerminate , std::mutex& mutex) :terminate(globalTerminate), _mutex(mutex) {}

    CommandType readFromKeyBoard::convertStringToEnum(std::string s) {
        if (s == "REGISTER")
            return REGISTER;
        if (s == "LOGIN")
            return LOGIN;
        if (s == "LOGOUT")
            return LOGOUT;
        if (s == "FOLLOW")
            return FOLLOW;
        if (s == "POST")
            return POST;
        if (s == "PM")
            return PM;
        if (s == "USERLIST")
            return USERLIST;

        return STAT;
    }

       void readFromKeyBoard::run(){
            while(terminate != true){
                string line;
                vector<string> words;

                getline(cin , line);
                boost::split(words, line ,boost::is_any_of(" "));
                CommandType enumCommand = convertStringToEnum(words[0]);

                switch (enumCommand){
                    case REGISTER:{

                    }
                        break;
                    case LOGIN:{

                    }
                        break;
                    case LOGOUT:{

                    }
                        break;
                    case FOLLOW:{

                    }
                        break;
                    case POST:{

                    }
                        break;
                    case PM:{

                    }
                        break;
                    case USERLIST:{

                    }
                        break;
                    case STAT:{

                    }
                        break;
                }
            }
        }

