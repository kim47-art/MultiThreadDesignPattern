#ifndef REQUEST
#define REQUEST
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <random>
#include <vector>
class Request{
private:
    std::string m_name;
    int m_number;
    std::random_device rnd;
    std::mt19937 mt;
    std::vector<std::string> buffer;

public:
    Request(std::string name, int number){
        this->m_name=name;
        this->m_number=number;
    };
    void Execute(std::string name) {
        std::cout << name << " executes " << this->toString() << std::endl;
        sleep(rnd()%3+1);
    };
    std::string toString(){
        return std::string("[ Request from " + this->m_name + " No." + std::to_string(this->m_number)+"]"); 
    };
};
#endif