#include <thread>
#include <future>
#include "WriterThread.hpp"
#include "ReaderThread.hpp"
#include "Data.hpp"
int main() {
    Data* data = new Data(10);
    ReaderThread* RE1 = new ReaderThread(data);
    ReaderThread* RE2 = new ReaderThread(data);
    ReaderThread* RE3 = new ReaderThread(data);
    ReaderThread* RE4 = new ReaderThread(data);
    ReaderThread* RE5 = new ReaderThread(data);
    WriterThread* WR1 = new WriterThread(data,"ABCDEFGHIJKLMNOPQTSTUVWXYZ");
    WriterThread* WR2 = new WriterThread(data,"abcdefghijklmnopqrstuvwxyz");      
    auto t0 = std::thread([RE1]{RE1->run(); });
    auto t1 = std::thread([RE2]{RE2->run(); });
    auto t2 = std::thread([RE3]{RE3->run(); });
    auto t3 = std::thread([RE4]{RE4->run(); });
    auto t4 = std::thread([RE5]{RE5->run(); });
    auto t5 = std::thread([WR1]{WR1->run(); });
    auto t6 = std::thread([WR2]{WR2->run(); });
    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    return 0;
}
