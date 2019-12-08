#include "WorkerThread.hpp"

WorkerThread::WorkerThread(std::string name, Channel* channel){
    this->channel=channel;
    this->name=name;
};
void WorkerThread::run(){
    while(true){
        Request* request = channel->takeRequest();
        request->Execute(this->name);
    }
};