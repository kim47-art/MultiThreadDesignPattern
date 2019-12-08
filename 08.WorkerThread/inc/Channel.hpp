#ifndef CHANNEL
#define CHANNEL
#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <fstream>
#include <iostream>
#include <vector>
#include "Request.hpp"
#include "WorkerThread.hpp"
#include "scope_guard.hpp"

class WorkerThread;
class Channel{
private:
    static int MAX_REQUEST;
    WorkerThread* p_WorkerThread;
    std::vector<Request*> requestQueue;
    int head;
    int tail;
    int count;
    std::vector<WorkerThread*> thread_pool;
    std::mutex put_mtx_;
    std::mutex take_mtx_;
    std::condition_variable cv;
public:
    Channel(int threads);
    void startWorkers();
    void putRequest(Request* request);
    Request* takeRequest();
};

#endif