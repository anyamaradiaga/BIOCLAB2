#ifndef MY_HEADER_KM
#define MY_HEADER_KM

#include "amaradiaga_pre_processing.hpp"
#include "amaradiaga_vector_ops.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::vector;

namespace kMean{       
    class cluster{
        public:
        cluster();
        void set_name(std::string namer);
        std::string get_name();
        float get_cluster_mean();
        void set_cluster_mean(float data);
        void set_distance(float data);
        float get_distance();
        private:
        std::string name;
        float mean;
        float distance;
        vector<float> cluster_data;
    };
}

#endif