/*
- Name: Anya Maradiaga
- Date: 15/02/22
- Description: ----
*/
#include "amaradiaga_vector_ops.hpp"
//a function that sums all of the outputs of an array
float MyVector::MyOps::calcSum(vector<float>* vect){
	float s = 0.0;
	int i;
	for (i = 0; i < sizeof(vect); i++) //going through every row
	{
		s += vect-> at(i); // s = s + v(i)
	}
	this -> sum = s;
    //return sum; //shouldn't return
}

//a function that subtracts one array from another element by element 
float MyVector::MyOps::calcSub(vector<float>*vect1, vector<float>*vect2){
    float p = 0.0;
    int i; 
    for(i=0; i<sizeof(vect1);i++){
        p = (vect1 -> at(i)) - (vect2 -> at(i));
    }
    this -> sub = p; 
    //return sub; //shouldn't return
}

//a function that divides all values in an array by a constant
float MyVector::MyOps::calcDiv(vector<float>* vect, int k){
    float d = 0.0; 
    int i; 
    for(i=0; i<sizeof(vect);i++){
        d = (vect -> at(i))/k; 
    }
    this -> div = d; 
}