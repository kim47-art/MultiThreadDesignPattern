#include <iostream>
#include "Host.hpp"
#include "Data.hpp"
int main() {
    std::cout << "main BEGIN" << std::endl;
    Host* host = new Host();
    Data* data1 = host->request(10, 'A');
    Data* data2 = host->request(20, 'B');
    Data* data3 = host->request(30, 'C');

    std::cout << "main otherJob BEGIN" << std::endl;
    
    try
    {
        sleep(10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "main otherJob ENG" << std::endl;

    std::cout << "data1 = " << data1->getContent() << std::endl;
    std::cout << "data2 = " << data2->getContent() << std::endl;
    std::cout << "data3 = " << data3->getContent() << std::endl;
    std::cout << "main END" << std::endl;
    return 0;
}
