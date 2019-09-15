#include <pthread.h>
#include <iostream>

#include "Gate.hpp"
#include "UserThread.hpp"
int main() {
    std::cout << "Testing Gate, hit CTRL+C to exit." << std::endl;
    Gate *gate = new Gate();
    pthread_t thread_1,thread_2,thread_3;
    UserThread Alice_thread(gate,"Alice","Alaska");
    UserThread Bob_thread(gate,"Bob","Brazil");  
    UserThread Chris_thread(gate,"Chris", "Canada");    
    pthread_create(&thread_1,NULL,UserThread::p_run,&Alice_thread);
    pthread_create(&thread_2,NULL,UserThread::p_run,&Bob_thread);    
    pthread_create(&thread_3,NULL,UserThread::p_run,&Chris_thread);
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    pthread_join(thread_3,NULL);
    return 0;
}