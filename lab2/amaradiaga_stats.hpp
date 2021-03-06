/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#ifndef MY_HEADER_H
#define MY_HEADER_H

//define libraries
#include <stdio.h>
#include <cstdlib>
#include <cstdio> 
#include <cstring> 
#include <stdlib.h>
#include <iostream>  
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
using namespace std; //used for cout, min, max arrays...
//using namespace myclass max; and define in cpp

//max function definition. 
//double calcMax(vector<double>& vect);
namespace MySpace{
    class MyClass{
        public: 
            float calcMean(vector<float> vect);
            float getMean();
            float calcMin(vector<float>* vect);
            float getMin();
            float calcMax(vector<float>* vect);
            float getMax();
            float calcSd(vector<float>* vect);
            float getSd();
            void calcHist(vector<float> vect);
            float calcSum(vector<float>* vect);
            vector<float> calcSub(vector<float>*vect1, vector<float>*vect2);
            vector<float> calcDiv(vector<float>* vect, float k);
        private:
            //where variables get listed
            float mean; 
            float min; 
            float max; 
            float std;
            vector<float> buckets;
            vector<float> bucket_vals;

};
}

//min function definition.
float calcMin(vector<float>* vect);
//mean function definition. 
float calcMean(vector<float>* vect);
//standard deviation function definition.
float calcSd(vector<float>* vect);
//histogram function definition
float calcHist(vector<float>* vect);
//sum function definition
float calcSum(vector<float>* vect);
//sub function definition
vector<float> calcSub(vector<float>*vect1, vector<float>*vect2);
//div function definition
vector<float> calcDiv(vector<float>* vect, float k);


#endif 