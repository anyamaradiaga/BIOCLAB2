#include "amaradiaga_corr.hpp"
using namespace std;


//create sum function
void MySpace1::MyClass1::calcSum(vector<float>* vect){
	float s = 0.0;
	int i;
	for (i = 0; i < sizeof(vect); i++) //going through every row
	{
		s += vect-> at(i); // s = s + v(i)
	}
	this -> sum = s;
}
float MySpace1::MyClass1::getSum(){
	return (this-> sum);
}
void MySpace1::MyClass1::CorrelationCalc(vector<float>* vect1, vector<float>* vect2){
    //float num,denom; 
    MySpace::MyClass mean;
    MySpace::MyClass std; 
    MySpace1::MyClass1 s; 
    vector<float>* m1,m2,std1,std2; 
    

    mean.calcMean(vect1); 
    this -> m1 = mean.getMean();  
    mean.calcMean(vect2);
    this -> m2 = mean.getMean();
    std.calcSd(vect1); 
    this -> std1 = std.getSd(); 
    std.calcSd(vect2); 
    this -> std2 = std.getSd(); 

    float num = (vect1 - m1)*(vect2 - m2);
    float denum = (vect1.size()*std1)*std2;

    





    
    
  
}

float MySpace1::MyClass1::getCorrelation(){
	return (this-> corr);
}