#ifndef HOST
#define HOST

#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <fstream>
#include <iostream>
#include <vector>

#include "Helper.hpp"
#include "scope_guard.hpp"
class Host {
private:
    Helper* helper = new Helper();

public:
    void request(int count, char c){
        std::cout << "  request(" << count << ", " << c << ") BEGIN" << std::endl;
        auto t0 = std::thread([this,count,c]{
            helper->handle(count, c); 
        });
        t0.detach();//request終了時にスレッドオブジェクトのデストラクタが呼ばれてしまうため、スレッドとオブジェクトの関連を切る
        std::cout << "  request(" << count << ", " << c << ") END" << std::endl;    
    }

};
#endif