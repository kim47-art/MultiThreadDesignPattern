#include "SaverThread.hpp"
SaverThread::SaverThread(std::string name, Data* data){
    this->name = name;
    this->data = data;
}
void* SaverThread::p_run(void *instance){
    SaverThread *self=(SaverThread *)instance;
    self->run();
}
void SaverThread::run() {
    try {
        while (true) {
            data->save();            // データを保存しようとする
            sleep(1);     // 約一秒休む
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    } 
}
