CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system -pthread

all: EchoClient
	g++ -o bin/BGSclient bin/connectionHandler.o bin/serverToClient.o bin/readFromKeyBoard.o bin/BGSclient.o $(LDFLAGS)

EchoClient: bin/connectionHandler.o bin/BGSclient.o bin/serverToClient.o bin/readFromKeyBoard.o

bin/connectionHandler.o: src/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp

bin/BGSclient.o: src/BGSclient.cpp
	g++ $(CFLAGS) -o bin/BGSclient.o src/BGSclient.cpp

bin/serverToClient.o: src/serverToClient.cpp
	g++ $(CFLAGS) -o bin/serverToClient.o src/serverToClient.cpp

bin/readFromKeyBoard.o: src/readFromKeyBoard.cpp
	g++ $(CFLAGS) -o bin/readFromKeyBoard.o src/readFromKeyBoard.cpp

.PHONY: clean
clean:
	rm -f bin/*