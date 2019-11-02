#include <thread>
#include <future>
#include "MakerThread.hpp"
#include "EaterThread.hpp"
#include "Table.hpp"
int main() {
    Table* table = new Table(3);
    MakerThread* MK1 = new MakerThread("MakerThread-1", table, 31415);
    MakerThread* MK2 = new MakerThread("MakerThread-2", table, 92653);
    MakerThread* MK3 = new MakerThread("MakerThread-3", table, 58979);
    EaterThread* ET1 = new EaterThread("EaterThread-1", table, 32384);
    EaterThread* ET2 = new EaterThread("EaterThread-2", table, 62643);
    EaterThread* ET3 = new EaterThread("EaterThread-3", table, 62643);

    auto t0 = std::thread([MK1]{MK1->run(); });
    auto t1 = std::thread([MK2]{MK2->run(); });
    auto t2 = std::thread([MK3]{MK3->run(); });
    auto t3 = std::thread([ET1]{ET1->run(); });
    auto t4 = std::thread([ET2]{ET2->run(); });
    auto t5 = std::thread([ET3]{ET3->run(); });
    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
