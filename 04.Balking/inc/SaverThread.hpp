#ifndef SAVERTHREAD
#define SAVERTHREAD

#include <unistd.h>
#include <string>
#include "Data.hpp"
class SaverThread{
private:
    Data* data;
    std::string name;
public:
    SaverThread(std::string name, Data* data);
    static void* p_run(void *instance);
    void run();
};
#endif