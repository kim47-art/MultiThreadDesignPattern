#ifndef READERTHREAD
#define READERTHREAD

#include <unistd.h>
#include <string>
#include "Data.hpp"
class ReaderThread{
private:
    Data* data;
    
public:
    ReaderThread(Data* data) {
        this->data = data;
    }
    void run() {
        try {
            while (true) {
                std::vector<std::string> readbuf = data->read();
                std::string output="";
                for(auto itr = readbuf.begin(); itr != readbuf.end(); ++itr) {
                    output += *itr;
                }
                std::cout << std::this_thread::get_id() << " reads " << output << std::endl;
            }
        } catch (std::exception& e) {
        }
    }
};
#endif