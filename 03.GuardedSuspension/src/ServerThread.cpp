#include "ServerThread.hpp"
ServerThread::ServerThread(RequestQueue* requestQueue, std::string name){
    this->name=name;
    this->requestQueue=requestQueue;
}
void* ServerThread::p_run(void *instance){
    ServerThread *self=(ServerThread *)instance;
    self->run();
}
void ServerThread::run(){
    for (int i = 0; i < 10000; i++) {
        Request request = this->requestQueue->getRequest();
        std::cout << this->name + " handles " + request.toString() << std::endl;
        try
        {
            sleep(rand()%10+1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}