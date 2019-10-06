#ifndef CLIENTTHREAD
#define CLIENTTHREAD

#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include "RequestQueue.hpp"
#include "Request.hpp"

class ClientThread {
private:
    RequestQueue* requestQueue;
    std::string name;

public:
    ClientThread(RequestQueue* requestQueue,std::string name);
    static void* p_run(void *instance);
    void run();
};
#endif