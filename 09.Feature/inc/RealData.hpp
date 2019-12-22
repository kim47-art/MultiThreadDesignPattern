#ifndef REALDATA
#define REALDATA
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>
#include "Data.hpp"
class RealData : public Data{
private:
    std::string content;

public:
    RealData(int count,char c){
        std::cout << "      making RealData(" << count <<"," << c << ") BEGIN" << std::endl;
        for (int i=0;i < count; i++){
            content += c;
            try
            {
                usleep(1000*100);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        } 
        std::cout << "      making RealData(" << count <<"," << c << ") END" << std::endl;

    };
    std::string getContent(){
        return content;
    };
};
#endif