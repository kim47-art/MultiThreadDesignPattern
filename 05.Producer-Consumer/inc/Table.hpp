#ifndef TABLE
#define TABLE

#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <fstream>
#include <iostream>
#include <vector>
class Table {
private:
    std::vector<std::string> buffer;
    int tail;  // 次にputする場所
    int head;  // 次にtakeする場所
    int count; // buffer内のケーキ数
    std::mutex mtx_;
    std::condition_variable cv;

public:
    Table(int count) {
        this->buffer.resize(count);
        this->head = 0;
        this->tail = 0;
        this->count = 0;
    }
    // ケーキを置く
    void put(std::string cake){
        std::unique_lock<std::mutex> lk(this->mtx_);
        std::cout << std::this_thread::get_id()  << " puts " << cake << std::endl;
        while (count >= buffer.size()) {
            cv.wait(lk, [this]{return (count < buffer.size());});
        }
        buffer[tail] = cake;
        tail = (tail + 1) % buffer.size();
        count++;
        cv.notify_all();
    }
    // ケーキを取る
    std::string take(){
        std::unique_lock<std::mutex> lk(this->mtx_);
        while (count <= 0) {
            cv.wait(lk, [this] {return (count > 0);});
        }
        std::string cake = buffer[head];
        head = (head + 1) % buffer.size();
        count--;
        cv.notify_all();
        std::cout << std::this_thread::get_id()  << " takes " << cake << std::endl;
        return cake;
    }
};
#endif