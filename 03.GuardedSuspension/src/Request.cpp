
#include "Request.hpp"
Request::Request(std::string _name){
    this->name=_name;
}
std::string Request::getName(){
    return name;
}
std::string Request::toString(){
    return "[ Request: name = " + name + " ]";
}