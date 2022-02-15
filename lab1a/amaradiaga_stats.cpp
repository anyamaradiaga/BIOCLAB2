/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#include "amaradiaga_stats.hpp"

//namespace class
//then constructor
//calculating the maximum

void MySpace::MyClass::calcMean(vector<float>* vect){
	float m = 0.0;
	int i;
	for (i = 0; i < sizeof(vect); i++) //going through every row
	{
		m += vect-> at(i);
	}
	m = m / sizeof(vect);
	this -> mean = m;

}
float MySpace::MyClass::getMean(){
	return (this-> mean);
}

void MySpace::MyClass::calcMax(vector<float>* vect){
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
}

float MySpace::MyClass::getMax(){
	return (this-> max);
}

void MySpace::MyClass::calcMin(vector<float>* vect){
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
}

float MySpace::MyClass::getMin(){
	return (this-> min);
}

void MySpace::MyClass::calcSd(vector<float>* vect){
	int i;
	float result = 0.0;
	MySpace::MyClass::calcMean(vect);
	float m = MySpace::MyClass::getMean(); //create instance of mean class
	
	for (i = 0; i < sizeof(vect); i++)
	{
		result += pow((vect-> at(i) - m), 2);
	}

	this -> std = sqrt(result / sizeof(vect));
}

float MySpace::MyClass::getSd(){
	return (this-> std);
}
/*
void MySpace::MyClass::calcHist(vector<float>* vect){
		//bin center should be at the mean
		MySpace::MyClass::calcMean(vect);
	    float m = MySpace::MyClass::getMean(); 

		//find max of data
		MySpace::MyClass::calcMax(vect);
		float max1 = MySpace::MyClass::getMax();

		//find min of data
		MySpace::MyClass::calcMin(vect);
		float min1 = MySpace::MyClass::getMin();

		//get standard deviation
		MySpace::MyClass::calcSd(vect);
		float std1 = MySpace::MyClass::getSd();

		//each bin should have a width of 0.4*sample standard deviation
		float bin_width = 0.4 * std1; 

		//bins should begin and end at sample mean ±3*(sample stddev), respectively.
		float bin_start = 0.3*std1, bin_end =(-0.3)*std1; 

		vector<float>*binedge;
		//int binedge[]={}; //array for binedge
		float bin_start = binedge -> at(0); //set the first edge to the bin start
		for (int i = bin_start; i < bin_end; i++) {
		binedge[i] = binedge[i - 1] + bin_width;
		}

		for (int i = 1; i <= bin_end; i++) {
		bin_center[i] = binedge[i] + ((1.0 / 2.0) * bin_width);
		}

		double count_array[]={}; //count array for histogram
		double count=0; 
		for(int i=0; i<= sizeof(vect);i++){
			for( int j=bin_start; j<=bin_end; j++){
				if(vect[i] < binedge[j + 1] && binedge[j] <= vect[i]){
					count ++;
				}
			}
			count_array[i] = count; //array that stores the count total
		}
		return(count);
	}
};*/