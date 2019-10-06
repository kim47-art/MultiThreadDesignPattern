#ifndef REQUESTQUEUE
#define REQUESTQUEUE

#include <queue>
#include "Request.hpp"

class RequestQueue {
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    std::queue<Request> queue;
public: 
    RequestQueue();
    Request getRequest();
    void putRequest(Request request);
};
#endif
