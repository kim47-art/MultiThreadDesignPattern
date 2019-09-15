#include "Gate.hpp"
void Gate::check(){
    if (name.substr(0,1) != address.substr(0,1)) {
        std::cout << "***** BROKEN ***** " << toString() << std::endl;
    }
}
Gate::Gate(){
    this->counter=0;
    this->name ="Nobody";
    this->address ="Noware";
}

void Gate::pass(std::string name, std::string address){
    
    this->counter++;
    this->name = name;
    this->address =address;
    check();
}
std::string Gate::toString(){
    std::ostringstream oss;
    oss << "No." << counter << ": "<< name <<", "<< address; 
    return oss.str();
}
