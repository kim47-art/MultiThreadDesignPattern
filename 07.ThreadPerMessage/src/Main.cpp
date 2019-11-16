#include <thread>
#include <future>
#include "Host.hpp"
int main() {
    std::cout << "main BEGIN" << std::endl;
    Host* host = new Host();
    host->request(10,'A');
    host->request(20,'B');
    host->request(30,'C');
    std::cout << "main END" << std::endl;
    sleep(40);//他の処理をやってる時間
    return 0;
}
