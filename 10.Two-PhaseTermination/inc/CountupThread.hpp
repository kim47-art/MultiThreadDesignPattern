#ifndef COUNTUPTHREAD
#define COUNTUPTHREAD
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <thread>
#include <future>
#include "scope_guard.hpp"
class CountupThread{
private:
    //カウンタの値
    long counter = 0;

    //終了要求が出されたらtrue
    volatile bool shutdownRequested = false;

    //作業
    void doWork(){
        try
        {
            counter++;
            std::cout << "doWork: counter = " << counter << std::endl;
            usleep(500*1000);
        }
        catch(const std::exception& e)
        {
            throw e;
        }
    }

    //終了処理
    void doShutdown(){
            std::cout << "doShutdown: counter = " << counter << std::endl;
    }

public:
    //終了要求
    void shutdownRequest(){
        shutdownRequested = true;
    //TODO:Javaのinterrupt()と同様の処理(sleep,wait中でも終了する)を実装すること
    }
    //終了要求が出されたかどうかのテスト
    bool isShutdownRequested(){
        return shutdownRequested;
    }

    //動作
    void run(){
        scoped_guard guard( [this]{ doShutdown(); } ) ;
        try {
            while(!isShutdownRequested()){
                doWork();
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

};
#endif