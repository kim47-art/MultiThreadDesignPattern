#ifndef CLIENTTHREAD
#define CLIENTTHREAD
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <thread>
#include <future>
#include "scope_guard.hpp"
#include "Log.hpp"
class ClientThread{
private:
    //スレッドの名前
    std::string name = "";

public:

    ClientThread(std::string name){
        this->name=name;
    }

    //動作
    void run(){
        std::cout << this->name << " BEGIN" << std::endl;
        std::cout << "name =" <<std::this_thread::get_id() << std::endl;
        for(int i=0;i<10;i++){
            std::stringstream ss;
            ss << "i = "<< i;
            Log::println(ss.str());

            try {
                usleep(100*1000);
            }catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        Log::close();
        std::cout << this->name << " END" << std::endl;
    }
};
#endif