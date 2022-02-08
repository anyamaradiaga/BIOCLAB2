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
#include <stdlib.h>
#include <iostream>  
#include <fstream>
#include <math.h>
#include <vector>
#include <array>
using namespace std; //used for cout, min, max arrays...
//using namespace myclass max; and define in cpp

//max function definition. 
double calcMax(double array[]);
//min function definition.
double calcMin(double array[]);
//mean function definition. 
float calcMean(double array[]);
//standard deviation function definition.
double calcSd(double array[]);
//histogram function definition
double calcHist(double array[]);


#endif 