#ifndef MY_HEADER_MP0
#define MY_HEADER_MP0

//include libraries
#include <iostream>
#include <unistd.h>

using namespace std; 

namespace Hacking{
    class TimeHacking{
        public: 
        TimeHacking(std::string objectToHack);
        int setTimeToHack(int seconds);
        int getTimeToHack();
        string getObjectToHack();
        int hackTime(); 
        private:
        int time_to_hack; 
        std::string objectToHack; 

    };
}

#endif 