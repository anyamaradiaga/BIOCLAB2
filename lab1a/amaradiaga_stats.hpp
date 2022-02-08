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
#include <math.h>
#include <vector>
#include <array>
using namespace std; //used for cout, min, max arrays...
//using namespace myclass max; and define in cpp

//max function definition. 
double calcMax(vector<double>& vect);
//min function definition.
double calcMin(vector<double>& vect);
//mean function definition. 
float calcMean(vector<double>& vect);
//standard deviation function definition.
double calcSd(vector<double>& vect);
//histogram function definition
double calcHist(vector<double>& vect);


#endif 