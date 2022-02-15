#include "amaradiaga_corr.hpp"
using namespace std;


//create sum function
float MySpace1::MyClass1::calcSum(vector<float>* vect1,vector<float>* vect2){
	float s = 0.0;
	int i;
	for (i = 0; i < sizeof(vect1); i++) //going through every row
	{
		s += vect1-> at(i) + vect2-> at(i); // s = s + v(i)
	}
	this -> sum = s;
}
float MySpace1::MyClass1::getSum(){
	return (this-> sum);
}
float MySpace1::MyClass1::CorrelationCalc(vector<float>* vect1, vector<float>* vect2){
    //float num,denom; 
    MySpace::MyClass stats; //for mean, sd
    MySpace1::MyClass1 sum; 

     //this->
    float m1,m2,std1,std2;
    float suma = 0.0; 
    // the below is good
    stats.calcMean(vect1); 
    m1 = stats.getMean();  

//the below is not good
    stats.calcMean(vect2);
    m2 = stats.getMean();
    stats.calcSd(vect1); 
    std1 = stats.getSd(); //i am struggling with this
    stats.calcSd(vect2); 
    std2 = stats.getSd(); 

   // float num = sum(x*y) -n*meanx*meany;
    for(int i=0; i< sizeof(vect1); i++){ //just doing one for loop bc all files have the same amount of points
        sum.calcSum(vect1,vect2) - sizeof(vect1)*m1*m2;
        //suma = i -> sum.getSum();
    }

    float denom = (vect1->size()*std1)*std2;

   // corr = (num/denom); 
  
}

float MySpace1::MyClass1::getCorrelation(){
	return (this-> corr);
}