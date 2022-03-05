/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#include "amaradiaga_stats.hpp"

//namespace class
//then constructor
//calculating the maximum

float MySpace::MyClass::calcMean(vector<float> vect){
    int index= vect.size();     
    int i=0;
    float sum=0;
    while(i<index){             
        sum=sum+vect[i];
        i++;
    }
    float answer=sum/index;
    this->mean=answer;        

}
float MySpace::MyClass::getMean(){
	return (this-> mean);
}

float MySpace::MyClass::calcMax(vector<float>* vect){
	int i;
	float m = vect->at(0);
	for (i = 0; i < sizeof(vect); i++) 
	{
		if (vect-> at(i) > m)
		{
			m = vect-> at(i);
		}
	}
	this -> max = m; 
	return m; 
}

float MySpace::MyClass::getMax(){
	return (this-> max);
}

float MySpace::MyClass::calcMin(vector<float>* vect){
	int i;
	float min_calc = vect->at(0);
	for (i = 0; i < sizeof(vect); i++) //going through every row
	{
		if (vect-> at(i) < min_calc)
		{
			min_calc = vect-> at(i);
		}
	}
	this -> min = min_calc; 
	return min_calc; 
}

float MySpace::MyClass::getMin(){
	return (this-> min);
}



void MySpace::MyClass::calcHist(vector<float> vect){

    float maximum = 0, minimum = 10000;
    int j = 0;

    float width = 0.4*(this->std); 
    float upperbound = this->mean+( 3*(this->std)); 
    float lowerbound= this->mean-(3*(this->std));
    float indexer=upperbound-width;                 
    int i=1;

        this->buckets.insert(buckets.begin(), upperbound);  

    while(indexer>lowerbound){     
        vector<float>::iterator testing= this->buckets.insert(buckets.begin(),1, indexer);
        indexer=indexer-width;
        i++;
        

    }
    
    int arr[buckets.size()];    
    for(int j=0; j<this->buckets.size(); j++){      
        arr[j]=0;
    }
    for(int i=0; i<vect.size();i++){                    
        for(int j=0; j<this->buckets.size(); j++){
            if(vect[i]>=this->buckets[j]){          
                if(vect[i]<this->buckets[j+1]){     
                    arr[j]++;                          
                }
            }
        }
    }

    for(int i=0;i<buckets.size();i++){
        vector<float>::iterator testing2= this->bucket_vals.insert(bucket_vals.begin(),1, arr[i]);    
    }   
	}
