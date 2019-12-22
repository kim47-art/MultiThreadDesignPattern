#ifndef FUTUREDATA
#define FUTUREDATA
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include "RealData.hpp"
#include "Data.hpp"
class FutureData: public Data{
private:
    RealData* realdata = nullptr;
    bool is_ready = false;
    std::mutex mtx_;
    std::condition_variable cv;

public:
    void setRealData(RealData* realdata){
        std::unique_lock<std::mutex> lk(this->mtx_); 
        if (is_ready){
            return; //balk
        }
        this->realdata=realdata;
        this->is_ready= true;
        cv.notify_all();
    };
    std::string getContent(){
        std::unique_lock<std::mutex> lk(this->mtx_); 
        while(!is_ready){
            try
            {
                cv.wait(lk);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        return realdata->getContent();

    };
};
#endif