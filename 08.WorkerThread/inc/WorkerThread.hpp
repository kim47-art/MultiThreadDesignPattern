#ifndef WORKER_THREAD
#define WORKER_THREAD
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <random>
#include "Channel.hpp"
#include "Request.hpp"
class Channel;
class WorkerThread{
private:
    Channel* channel;
    std::string name;
public:
    WorkerThread(std::string name, Channel* channel);
    void run();
};
#endif