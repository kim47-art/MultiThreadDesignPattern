#ifndef MAKERTHREAD
#define MAKERTHREAD
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <random>
#include "Table.hpp"
class MakerThread{
private:
    std::random_device rnd;
    std::mt19937 mt;
    std::string name;
    Table* table;
    static int id;

    int nextId() {
        return id++;
    }
public:
    MakerThread(std::string name, Table* table, long seed){
        this->name=name;
        this->table=table;
        mt.seed(seed);
    }
    void run(){
        std::cout << std::this_thread::get_id() <<" is "<<this->name << std::endl;
        try {
            while (true) {
                sleep(rnd()%10+1);
                std::string cake = "[ Cake No." + std::to_string(nextId()) + " by " + name + " ]";
                table->put(cake);
            }
        }catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        } 
    }
};
int MakerThread::id = 0;
#endif