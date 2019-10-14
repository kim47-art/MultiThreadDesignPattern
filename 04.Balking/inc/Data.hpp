#ifndef DATA
#define DATA

#include <string>
#include <thread>
#include <mutex>
#include <fstream>
#include <iostream>
class Data {
private:
    std::string filename;
    std::string content;
    bool changed;    
    void doSave();
    std::mutex mtx;
public:
    Data(std::string filename,std::string content);
    void change(std::string newContent);
    void save();
};
#endif