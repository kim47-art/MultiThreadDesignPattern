#ifndef CLIENT_THREAD
#define CLIENT_THREAD
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <random>
#include "Channel.hpp"
#include "Request.hpp"
class ClientThread{
private:
    Channel* channel;
    std::random_device rnd;
    std::mt19937 mt;
    std::string name;
    std::string getName(){
        return this->name;
    };
public:
    ClientThread(std::string name, Channel* channel){
        this->channel=channel;
        this->name=name;
    };  
    void run(){
        for(int i=0;true;i++){
            Request* request =new Request(getName(), i);
            channel->putRequest(request);
            sleep(rnd()%3+1);
        }
    };
};
#endif