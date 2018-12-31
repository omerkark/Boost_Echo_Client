//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/31/18.
//
#include <boost/asio/ip/tcp.hpp>
#include <stdlib.h>
#include <iostream>
#include "../include/connectionHandler.h"
#include <boost/algorithm/string.hpp>

using namespace std;

int main (int argc, char *argv[]) {

    bool terminate = false;

    std::string host = "127.0.0.1";
    short port = 7777;
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    cout << "enter a line \n";
    string line;
    vector<string> words;

    getline(cin , line);
    boost::split(words, line ,boost::is_any_of(" "));

    for(string str: words){
        cout << str << " ;) ";
    }



}