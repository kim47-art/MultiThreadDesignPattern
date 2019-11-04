#ifndef DATA
#define DATA

#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <fstream>
#include <iostream>
#include <vector>

#include "ReadWriteLock.hpp"
#include "scope_guard.hpp"
class Data {
private:
    std::vector<std::string> buffer;
    ReadWriteLock* lock = new ReadWriteLock();  
    
    std::vector<std::string> doRead() {
        std::vector<std::string> newbuf(buffer); 
        slowly();
        return newbuf;
    }
    void doWrite(std::string c) {
        for (int i = 0; i < buffer.size(); i++) {
            buffer[i] = c;
            slowly();
        }
    }
    void slowly() {
        try {
            std::chrono::milliseconds dura( 50 );
            std::this_thread::sleep_for( dura );    // 50 ミリ秒
        } catch (std::exception& e){
        }
    }


public:
    Data(int size) {
        this->buffer.resize(size);
        for (int i = 0; i < this->buffer.size(); i++){
            this->buffer[i] = '*';
        }
    }

    std::vector<std::string> read() {
        lock->readLock();
        {
            scoped_guard guard( [this]{ lock->readUnlock(); } ) ;
            return doRead();
        }
    }
    void write(std::string c) {
        lock->writeLock();
        {
            scoped_guard guard( [this]{ lock->writeUnlock(); } ) ;
            return doWrite(c);
        }
    }
};
#endif