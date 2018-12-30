//
// Created by omerkark@wincs.cs.bgu.ac.il on 12/30/18.
//

#include <mutex>
#include <EncoderDecoder.h>

class readFromKeyBoard{

    private:
        std::mutex & _mutex;
        EncoderDecoder encoderDecoder;

    public:
        readFromKeyBoard (int id, std::mutex& mutex) : _id(id), _mutex(mutex) {}

        void run(){

        }
    };

