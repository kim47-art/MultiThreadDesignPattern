#ifndef WRITERTHREAD
#define WRITERTHREAD
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <random>
#include "Data.hpp"
class WriterThread{
private:
    std::random_device rnd;
    std::mt19937 mt;
    Data* data;
    static int index;
    std::string filler;

    char nextchar() {
        char c = filler[index];
        index++;
        if (index >= filler.size()) {
            index = 0;
        }
        return c;
    };

public:
    WriterThread(Data* data, std::string filler){
        this->data=data;
        this->filler=filler;
    }
    void run(){
        try {
            while (true) {
                char c = nextchar();
                data->write(std::string(&c));
                sleep(rnd()%3+1);
            }
        }catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        } 
    }
};
int WriterThread::index = 0;
#endif