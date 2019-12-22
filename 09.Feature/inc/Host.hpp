#ifndef HOST
#define HOST
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <thread>
#include <future>
#include "FutureData.hpp"
#include "RealData.hpp"
#include "Data.hpp"
class Host{
private:
public:
    Data* request(int count, char c){
        std::cout << "  request(" << count << ", " << c << ") BEGIN" << std::endl;
        
        //(1)FutureDataのインスタンスを作る
        FutureData* future = new FutureData();

        //(2)RealDataを作るための新しいスレッドを起動する
        auto t0 = std::thread([count,c,future]{
            RealData* realdata = new RealData(count,c);
            future->setRealData(realdata);
        });
        t0.detach();

        std::cout << "  request(" << count << ", " << c << ") END" << std::endl;
        
        //(3)FutureDataのインスタンスを戻り値とする
        return future;
    };  
};
#endif