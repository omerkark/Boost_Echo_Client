#include <serverToClient.h>

//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/30/18.
//
using namespace std;
serverToClient::serverToClient(ConnectionHandler &connectionHandler,bool& globalLogin):connectionHandler(connectionHandler),login(globalLogin){}

void serverToClient::run() {
    while (!terminate) {
               decode();
    }
}

void serverToClient::decode(){
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
            string content = "";
            connectionHandler.getFrameAscii(content, '\0');
            cout << userName + " " + content << endl;
        }
            break;

        case 10:{
            char Opcode[2];
            connectionHandler.getBytes(Opcode,2);
            switch (bytesToShort(Opcode))
            case 2: {
                cout<<"ACK 2";
                login = true;
            }

            case 3: {
                cout << "ACK 3";
                connectionHandler.close();
            }
            break;

            case 4:{
                printFunction("ACK 4 ");
            }
            break;

            case 7:{
                printFunction("ACK 7 ");
            }
            break;

            case 8:{
                char numOfPost[2];
                char numOffollowers[2];
                char numOffollowing[2];
                connectionHandler.getBytes(numOfPost,2);
                connectionHandler.getBytes(numOffollowers,2);
                connectionHandler.getBytes(numOffollowing,2);
                cout<<"ACK 8 "<<to_string(bytesToShort(numOfPost))<<" "<<
                    to_string(bytesToShort(numOffollowers))<<" "<<to_string(bytesToShort(numOffollowing));
            }
            break;

            default:{
                cout<<"ACK "<<to_string(bytesToShort(Opcode));

            }
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
void serverToClient::printFunction(string Case) {
    char numOfFollows[2];
    connectionHandler.getBytes(numOfFollows, 2);

    //check if it works with int and not short
    int numberOfFollowers = bytesToShort(numOfFollows);
    cout << Case << to_string(numberOfFollowers) << " ";
    string followList;
    connectionHandler.getFrameAscii(followList, '\0');
    cout << followList;
}


short serverToClient::bytesToShort(char* bytesArr)
{
    short result = (short)((bytesArr[0] & 0xff) << 8);
    result += (short)(bytesArr[1] & 0xff);
    return result;
}

void serverToClient::shortToBytes(short num, char* bytesArr)
{
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}