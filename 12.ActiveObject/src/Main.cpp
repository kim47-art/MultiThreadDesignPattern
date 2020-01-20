#include <thread>
#include <future>
#include "ClientThread.hpp"
int main() {

    //スレッドの起動
    auto t0 = std::thread([]{
        ClientThread* t = new ClientThread("Alice");
        t->run();
    });

    auto t1 = std::thread([]{
        ClientThread* t = new ClientThread("Bobby");
        t->run();
    });

    auto t2 = std::thread([]{
        ClientThread* t = new ClientThread("Chris");
        t->run();
    });
    t0.join();
    t1.join();
    t2.join();
    return 0;
}
