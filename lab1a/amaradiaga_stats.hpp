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
            float calcMean(vector<float>* vect);
            float getMean();
            float calcMin(vector<float>* vect);
            float getMin();
            float calcMax(vector<float>* vect);
            float getMax();
            float calcSd(vector<float>* vect);
            float getSd();
            float calcHist(vector<float>* vect);
        private:
            //where variables get listed
            float mean; 
            float min; 
            float max; 
            float std;

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


#endif 