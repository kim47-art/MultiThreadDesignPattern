#include "RequestQueue.hpp"
RequestQueue::RequestQueue(){
        pthread_mutexattr_t attr_t;
        pthread_mutexattr_settype(&attr_t,PTHREAD_MUTEX_ERRORCHECK_NP);
        pthread_mutex_init(&(this->mutex),&attr_t); 
}
Request RequestQueue::getRequest(){
    try{
        pthread_mutex_lock(&(this->mutex));
        while(queue.empty()){
            try{
                pthread_cond_wait(&(this->cond),&(this->mutex));
            }catch(const std::exception& e){
            }
        }
        Request ret=queue.front();
        queue.pop();
        pthread_mutex_unlock(&(this->mutex));
        return ret;

    }catch (const char* e){
        pthread_mutex_unlock(&(this->mutex));
        throw e;
    }
}

void RequestQueue::putRequest(Request request){
    try{
        pthread_mutex_lock(&(this->mutex));
        queue.push(request);
        pthread_mutex_unlock(&(this->mutex));
        pthread_cond_signal(&(this->cond));
    }catch (const char* e){
        pthread_mutex_unlock(&(this->mutex));
        throw e;
    }
}