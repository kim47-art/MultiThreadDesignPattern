
#include "Person.hpp"
Person::Person(std::string _name,std::string _address):name(name),address(_address){
}
std::string Person::getName(){
    return name;
}
std::string Person::getAddress(){
    return address;
}
std::string Person::toString(){
    return "[ Person: name = " + name + ", address = " + address + " ]";
}