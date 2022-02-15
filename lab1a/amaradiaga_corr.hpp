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
        float CorrelationCalc(vector<float>* vect1, vector<float>* vect2);
        float getCorrelation();
        float calcSum(vector<float>* vect1,vector<float>* vect2);
        float getSum();
        private: 
        float corr, sum; 
        vector<float>* m1,m2,std1,std2; 
    };
}

float CorrelationCalc(vector<float>* vect1, vector<float>* vect2);
float calcSum(vector<float>* vect1,vector<float>* vect2);
#endif 
