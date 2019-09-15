#ifndef GATE
#define GATE

#include <string>
#include <sstream>
#include <iostream>
class Gate {
private:
    int counter;
    std::string name;
    std::string address;
    void check();

public:
    Gate();
    void pass(std::string name, std::string address);
    std::string toString();
};
#endif