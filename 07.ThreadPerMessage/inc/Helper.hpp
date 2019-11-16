#ifndef HELPER
#define HELPER
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
class Helper{
private:
    void slowly() {
        try{
            sleep(1);
        }catch (std::exception& e) {
        }
    };

public:
    void handle(int count, char c){
        std::cout << "  handle(" << count << ", " << c << ") BEGIN" << std::endl; 
        for (int i = 0; i < count; i++){
            slowly();
            std::cout << c << std::endl;
        }            
        std::cout << "" << std::endl;
        std::cout << "  handle(" << count << ", " << c << ") END" << std::endl; 
    }
};
#endif