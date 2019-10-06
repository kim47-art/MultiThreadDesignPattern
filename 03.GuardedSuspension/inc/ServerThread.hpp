#ifndef SERVERTHREAD
#define SERVERTHREAD

#include <stdlib.h>
#include <unistd.h>
#include "RequestQueue.hpp"
#include "Request.hpp"

class ServerThread {
private:
    RequestQueue* requestQueue;
    std::string name;

public:    
    ServerThread(RequestQueue* requestQueue, std::string name);
    static void* p_run(void *instance);
    void run();
};
#endif