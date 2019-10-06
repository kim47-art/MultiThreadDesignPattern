#ifndef REQUEST
#define REQUEST

#include <string>
#include <sstream>
#include <iostream>
class Request {
private:
    std::string name;    
public:
    Request(std::string _name);
    std::string getName();
    std::string toString();
};
#endif