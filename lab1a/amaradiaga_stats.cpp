/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#include "amaradiaga_stats.hpp"

//namespace class
//then constructor
//calculating the maximum
using namespace StatsSpace; 

void StatsSpace::StatsClass::calcMean(vector<float> vect){
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
float StatsSpace::StatsClass::getMean(){
	return (this-> mean);
}

void StatsSpace::StatsClass::calcMax(vector<float> vect){
    int i=0;
    float m=0;
	while(i<vect[i]){
		if (vect[i]>m ){
			m = vect[i];
		}
        else{}
        i++;
	}
	this -> max = m;  
}

float StatsSpace::StatsClass::getMax(){
	return (this-> max);
}

void StatsSpace::StatsClass::calcMin(vector<float> vect){
    int i=0;
    float m=0;
	while(i<vect[i]){
		if (vect[i]<m ){
			m = vect[i];
		}
        else{}
        i++;
	}
	this -> min = m;  
}

float StatsSpace::StatsClass::getMin(){
	return (this-> min);
}

void StatsSpace::StatsClass::calcHist(vector<float> vect){

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
