#ifndef CHANGERTHREAD
#define CHANGERTHREAD
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include "Data.hpp"
class ChangerThread{
private:
    std::string name;
    Data* data;
public:
    ChangerThread(std::string name, Data* data);
    static void* p_run(void *instance);
    void run();
};
#endif