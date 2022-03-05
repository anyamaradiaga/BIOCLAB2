/*
- Name: Anya Maradiaga
- Date: 15/02/22
- Description: ----
*/
#include "amaradiaga_vector_ops.hpp"

MyVectorSpace::MyOpsClass::MyOpsClass(){
}

MyVectorSpace::MyOpsClass::MyOpsClass(vector<float>* vect){
}

MyVectorSpace::MyOpsClass::MyOpsClass(vector<float>*vect1, vector<float>*vect2){
}

MyVectorSpace::MyOpsClass::MyOpsClass(vector<float>* vect, float k){
}

//a function that sums all of the outputs of an array
float MyVectorSpace::MyOpsClass::calcSum(vector<float>* vect){
	float s = 0;
	int i;
	for (i = 0; i < sizeof(vect); i++) //going through every row
	{
		s += vect-> at(i); // s = s + v(i)
	}
    return s; 
}

//a function that subtracts one array from another element by element 
vector<float> MyVectorSpace::MyOpsClass::calcSub(vector<float>*vect1, vector<float>*vect2){
    std::vector<float> p; 
    int i; 
    for(i=0; i<vect1 -> size();i++){
        p.push_back(vect1 -> at(i) - vect2 -> at(i));
    }
    return p; 
    //return sub; //shouldn't return
}

//a function that divides all values in an array by a constant
vector<float> MyVectorSpace::MyOpsClass::calcDiv(vector<float>* vect, float k){
    std::vector<float> d; 
    int i; 
    for(i=0; i<vect -> size();i++){
        d.push_back(vect -> at(i)/k); 
    }
    return d; 
}