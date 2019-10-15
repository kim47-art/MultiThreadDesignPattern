#ifndef PERSON
#define PERSON

#include <string>
#include <sstream>
#include <iostream>
class Person {
private:
    const std::string name;    
    const std::string address;
    Person(std::string _name);
public:
    Person(std::string name,std::string address);
    std::string getName();
    std::string getAddress();
    std::string toString();
};
#endif