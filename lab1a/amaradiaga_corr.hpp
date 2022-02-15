#ifndef MY_HEADER_H0
#define MY_HEADER_H0

#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include "amaradiaga_stats.hpp"

using namespace std;

//correlation constant function that takes two data files as inputs 
namespace MySpace1{
    class MyClass1{
        public:
        void CorrelationCalc(vector<float>* vect1, vector<float>* vect2);
        float getCorrelation();
        void calcSum(vector<float>* v);
        float getSum();
        private: 
        float corr, sum; 
    };
}

float CorrelationCalc(vector<float>* vect1, vector<float>* vect2);
float calcSum(vector<float>* v);
#endif 
