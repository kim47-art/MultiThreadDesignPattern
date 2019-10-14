
#include "ChangerThread.hpp"
ChangerThread::ChangerThread(std::string name, Data* data){
        this->name = name;
        this->data = data;
}
void* ChangerThread::p_run(void *instance){
    ChangerThread *self=(ChangerThread *)instance;
    self->run();
}
void ChangerThread::run(){
    try {
        for (int i = 0; true; i++) {
            std::ostringstream ss;
            ss << i;
            data->change("No." + ss.str());             //データを変更する
            //sleep(rand()%10+1); //仕事のつもり
            usleep((rand()%10+1)*1000000/10);//仕事のつもり
            data->save();                        //明示的に保存する
            }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    } 
}
