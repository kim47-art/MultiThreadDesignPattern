#include <pthread.h>
#include <iostream>

#include "Person.hpp"
#include "PrintPersonThread.hpp"
int main() {
    Person *alice = new Person("Alice","Alaska");
    pthread_t thread_t_1,thread_t_2,thread_t_3;
    PrintPersonThread thread_1(alice,"thread_1");
    PrintPersonThread thread_2(alice,"thread_2");  
    PrintPersonThread thread_3(alice,"thread_3");  
    pthread_create(&thread_t_1,NULL,PrintPersonThread::p_run,&thread_1);
    pthread_create(&thread_t_2,NULL,PrintPersonThread::p_run,&thread_2);    
    pthread_create(&thread_t_3,NULL,PrintPersonThread::p_run,&thread_3);
    pthread_join(thread_t_1,NULL);
    pthread_join(thread_t_2,NULL);
    pthread_join(thread_t_3,NULL);
    return 0;
}