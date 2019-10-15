#ifndef PRINTPERSONTHREAD
#define PRINTPERSONTHREAD

#include <iostream>
#include <string>

#include "Person.hpp"
class PrintPersonThread {
private:
    Person* person;
    std::string name;
public:
    PrintPersonThread(Person* person,std::string name);
    static void* p_run(void *instance);
    void run();
};
#endif
