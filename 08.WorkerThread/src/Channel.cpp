#include "Channel.hpp"
int Channel::MAX_REQUEST=100;
Channel::Channel(int threads){
    this->requestQueue = std::vector<Request*> (MAX_REQUEST);
    this->count = 0;
    this->thread_pool.resize(threads);
    for(int i=0; i < thread_pool.size();i++){
        thread_pool[i]= new WorkerThread(std::string("Worker-" + std::to_string(i)),this);
    }
};
void Channel::startWorkers() {
    for (int i = 0; i < thread_pool.size(); i++) {
        std::cout << i << std::endl;
        auto t0 = std::thread([this,i]{
            thread_pool[i]-> run();
        });
        t0.detach();
    }

};
void Channel::putRequest(Request* request) {
    std::unique_lock<std::mutex> lk(this->put_mtx_);
    while (count >= requestQueue.size()) {
        try {
            cv.wait(lk);
        }catch (std::exception& e) {
        }
    }
    
    requestQueue[tail]=request;
    tail = (tail+1) % requestQueue.size();
    count++;
    cv.notify_all();
};
Request* Channel::takeRequest() {
    std::unique_lock<std::mutex> lk(this->take_mtx_);
    while (count <= 0) {
        try {
            cv.wait(lk);
        } catch (std::exception& e) {
        }
    }
    Request* request = requestQueue[head];
    head = (head + 1 ) % requestQueue.size();
    count--;
    cv.notify_all();
    return request;
};
