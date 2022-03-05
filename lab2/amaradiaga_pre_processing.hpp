#ifndef MY_HEADER_PP
#define MY_HEADER_PP
#include "amaradiaga_stats.hpp"
#include "amaradiaga_vector_ops.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
//using namespace std;

using std::vector; 

namespace PreProcessing{
    class MyProcess {
        public: 
        MyProcess(); 
        vector<float> get_log_ratio();
        void set_log_ratio(vector<float> vector1, vector<float> vector2);
        private:
        vector<float> log_ratio;
    };
}

#endif