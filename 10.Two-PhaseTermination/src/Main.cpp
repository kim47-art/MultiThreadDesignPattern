#include <iostream>
#include <thread>
#include <future>
#include "CountupThread.hpp"
int main() {
    std::cout << "main: BEGIN" << std::endl;
    try
    {
        //スレッドの起動
        CountupThread* t = new CountupThread();
        auto t0 = std::thread([t]{
            t->run();
        });
        //少し時間を開ける
        sleep(10);

        //スレッドの終了要求
        std::cout << "main: shutdownRequest" << std::endl;        
        t->shutdownRequest();

        std::cout << "main: join" << std::endl;        
        
        //スレッドの終了を待つ
        t0.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "main: END" << std::endl;
    return 0;
}
