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
#include<algorithm>
#include <array>
#include <iostream>  
using namespace std; 

namespace MyVectorSpace{
     class MyOpsClass{
        public:
        MyOpsClass();
        MyOpsClass(vector<float>* vect);
        MyOpsClass(vector<float>*vect1, vector<float>*vect2);
        MyOpsClass(vector<float>* vect, float k);

        float calcSum(vector<float>* vect);
        vector<float> calcSub(vector<float>*vect1, vector<float>*vect2);
        vector<float> calcDiv(vector<float>* vect, float k);

    };
}

#endif 