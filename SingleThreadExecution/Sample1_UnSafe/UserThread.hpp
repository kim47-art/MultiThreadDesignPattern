#ifndef USERTHREAD
#define USERTHREAD

#include <iostream>
#include <string>

#include "Gate.hpp"
class UserThread {
private:
    Gate *gate;
    std::string myname;
    std::string myaddress;
public:
    UserThread(Gate *gate,std::string myname, std::string myaddress);
    static void* p_run(void *instance);
    void run();
};
#endif
