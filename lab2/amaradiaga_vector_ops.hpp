/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <cstdlib>
#include <cstdio> 
#include <cstring> 
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include <iostream>  
using namespace std; 

namespace MyVector{
    class MyOps{
        public:
        float calcSum(vector<float>* vect);
        float calcSub(vector<float>* vect1,vector<float>* vect2);
        float calcDiv(vector<float>*vect, int k); //divides all values by a constant K
        private: 
        float sub, sum, div; 
    };
}

float calcSum(vector<float>* vect1,vector<float>* vect2);
float calcSub(vector<float>* vect1,vector<float>* vect2);

#endif 