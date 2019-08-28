#include "Gate.hpp"
void Gate::check(){
    if (name.substr(0,1) != address.substr(0,1)) {
        std::cout << "***** BROKEN ***** " << toString() << std::endl;
    }
    if (this->counter%1000000==0){
        std::cout << this->counter << std::endl;
    }
}
Gate::Gate(){
        this->counter=0;
        this->name ="Nobody";
        this->address ="Noware";
        pthread_mutexattr_t attr_t;
        pthread_mutexattr_settype(&attr_t,PTHREAD_MUTEX_ERRORCHECK_NP);
        pthread_mutex_init(&(this->mutex),&attr_t); 
}

void Gate::pass(std::string name, std::string address){
    try{
        pthread_mutex_lock(&(this->mutex));
        this->counter++;
        this->name = name;
        this->address =address;
        check();
        pthread_mutex_unlock(&(this->mutex));
    }catch (const char* e){
        pthread_mutex_unlock(&(this->mutex));
        throw e;
    }
}
std::string Gate::toString(){
    std::ostringstream oss;
    oss << "No." << counter << ": "<< name <<", "<< address; 
    return oss.str();
}
