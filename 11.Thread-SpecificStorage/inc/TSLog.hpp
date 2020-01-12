#ifndef TSLOG
#define TSLOG
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
class TSLog{
private:
    std::ofstream writer;

public:

    TSLog(std::string filename){
        try
        {
            writer.open(filename,std::ios::out);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    // ログを書く
    void println(std::string s){
        writer<<s<<std::endl;
    };

    // ログを閉じる
    void close(){
        writer<<"==== End of log ===="<<std::endl;
        writer.close();
    }
};
#endif