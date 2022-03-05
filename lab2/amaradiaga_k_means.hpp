/*
------------------------------------------------------------------------
- Name: Anya Maradiaga 
- Due Date: March 4, 2022
- Description: This is the header file for clustering/distance functions 
------------------------------------------------------------------------
*/

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
        cluster(string, float);

        //variables
        float mean;
        string name;
        vector<float> cluster_data;

        //functions
        void set_name(string);
        string get_name();
        void set_cluster_mean(vector<float>);
        float get_cluster_mean();
        float set_distance(float point);
    };
}

#endif