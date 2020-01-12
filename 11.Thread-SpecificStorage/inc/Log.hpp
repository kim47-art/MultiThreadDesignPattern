#ifndef LOG
#define LOG
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <thread>
#include <future>
#include "TSLog.hpp"
class Log{
private:

public:

    // ログを書く
    static void println(std::string s){
        getTSLog()->println(s);
    };

    // ログを閉じる
    static void close(){
        getTSLog()->close();
    }

    // スレッド固有のログを得る
    static TSLog* getTSLog(){
        thread_local TSLog* tsLog;
        // そのスレッドからの呼び出しがはじめてなら、新規作成する
        if(tsLog == nullptr){
            std::stringstream ss;
            ss << std::this_thread::get_id() << "-log.txt";
            std::string mystring = ss.str();
            tsLog = new TSLog(mystring);
        }
        return tsLog;
    }
};
#endif