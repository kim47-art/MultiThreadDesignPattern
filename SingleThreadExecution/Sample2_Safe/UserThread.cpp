#include "UserThread.hpp"

UserThread::UserThread(Gate *gate,std::string myname, std::string myaddress){
    this->gate=gate; 
    this->myname=myname;
    this->myaddress=myaddress;
}
void *UserThread::p_run(void *instance){
    UserThread *self=(UserThread *)instance;
    self->run();
}
void UserThread::run(){
    std::cout << myname << " BEGIN" << std::endl;
    while (true)
    {
        gate->pass(myname,myaddress);
    }
}

