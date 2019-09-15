#include "PrintPersonThread.hpp"
PrintPersonThread::PrintPersonThread(Person* person,std::string name){
    this->person=person;
    this->name=name;
}
void* PrintPersonThread::p_run(void *instance){
    PrintPersonThread *self=(PrintPersonThread *)instance;
    self->run();
}
void PrintPersonThread::run(){
    while (true)
    {
        std::cout << this->name <<" prints" << person->toString() <<std::endl;
    }
}

