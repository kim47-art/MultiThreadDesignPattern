#include <pthread.h>
#include <iostream>

#include "RequestQueue.hpp"
#include "ServerThread.hpp"
#include "ClientThread.hpp"
int main() {
    RequestQueue* requestQueue= new RequestQueue();
    pthread_t thread_t_1,thread_t_2;
    ServerThread thread_1(requestQueue,"Bobby");
    ClientThread thread_2(requestQueue,"Alice");    
    pthread_create(&thread_t_1,NULL,ServerThread::p_run,&thread_1);
    pthread_create(&thread_t_2,NULL,ClientThread::p_run,&thread_2);    
    pthread_join(thread_t_1,NULL);
    pthread_join(thread_t_2,NULL);
    return 0;
}