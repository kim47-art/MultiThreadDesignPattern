#include <thread>
#include "Data.hpp"
#include "ChangerThread.hpp"
#include "SaverThread.hpp"
int main() {
    Data* data = new Data("data.txt", "(empty)");
    ChangerThread* changerThread= new ChangerThread("ChangerThread", data);
    SaverThread* saverThread = new SaverThread("SaverThread", data);
    std::thread t0(ChangerThread::p_run,changerThread);
    std::thread t1(SaverThread::p_run,saverThread);
    std::cout << "t0 thread:" << t0.get_id() << std::endl;
    std::cout << "t1 thread:" << t1.get_id() << std::endl;
    t0.join();
    t1.join();
    return 0;
}
