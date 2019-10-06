#include "ClientThread.hpp"
ClientThread::ClientThread(RequestQueue* requestQueue, std::string name){
    this->name=name;
    this->requestQueue=requestQueue;
}
void* ClientThread::p_run(void *instance){
    ClientThread *self=(ClientThread *)instance;
    self->run();
}
void ClientThread::run(){
    for (int i = 0; i < 10000; i++) {
        std::ostringstream ss;
        ss << i;
        std::string name = "No."+ ss.str();
        Request* request = new Request(name);
        std::cout << this->name + " requests " + request->toString() << std::endl;
        this->requestQueue->putRequest(*request);
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
 
