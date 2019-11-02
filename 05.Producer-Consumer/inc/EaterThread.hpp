#ifndef EATERTHREAD
#define EATERTHREAD

#include <unistd.h>
#include <string>
#include "Table.hpp"
class EaterThread{
private:
    std::random_device rnd;
    std::mt19937 mt;
    std::string name;
    Table* table;
public:
    EaterThread(std::string name, Table* table, long seed){
        this->name=name;
        this->table=table;
        mt.seed(seed);
    }
    void run(){
        std::cout << std::this_thread::get_id() <<" is "<<this->name << std::endl;
        try {
            while (true) {
                std::string cake = table->take();
                sleep(rnd()%10+1);
            }
        }catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        } 
    }
};
#endif