#cmake_minimum_required(VERSION 3.12)
#project(Boost_Echo_Client)
#
#set(CMAKE_CXX_STANDARD 11)
#find_package(Boost COMPONENTS system filesystem thread REQUIRED)
#IF (Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIR})
#endif()
#
#
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lboost_thread")
#include_directories(cmake-build-debug/include)
#
#add_executable(Boost_Echo_Client
#        include/connectionHandler.h
#        include/EncoderDecoder.h
#        src/connectionHandler.cpp
#        src/echoClient.cpp
#        src/EncoderDecoder.cpp src/readFromKeyBoard.cpp src/serverToClient.cpp
#        src/readFromKeyBoard.cpp src/serverToClient.cpp)

cmake_minimum_required(VERSION 3.12)
project(Boost_Echo_Client)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system filesystem REQUIRED)
IF(Boost_FOUND)
    include_directories(${Boost_LIBRARY_DIR})
endif()
#link_directories(${Boost_LIBRARY_DIR})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11 -pthread -lboost_thread")

include_directories(include)

add_executable(Boost_Echo_Client
                include/connectionHandler.h
                src/connectionHandler.cpp
                src/echoClient.cpp
                src/readFromKeyBoard.cpp src/serverToClient.cpp
                src/readFromKeyBoard.cpp src/serverToClient.cpp
                makefile include/readFromKeyBoard.h src/BGSclient.cpp
                include/serverToClient.h)
target_link_libraries(Boost_Echo_Client LINK_PUBLIC ${Boost_LIBRARIES})