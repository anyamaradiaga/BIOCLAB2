/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#include "amaradiaga_stats.hpp"

//namespace class
//then constructor
//calculating the maximum

using namespace std;

class Max{
	public:
double calcMax(vector<double>& vect)
{
	int i;
	double max = vect[0];
	for (i = 0; i < sizeof(vect); i++) 
	{
		if (vect[i] > max)
		{
			max = vect[i];
		}
	}
	return(max);
}
};


//calculating the minimum
class Min{
	public:
double calcMin(vector<double>& vect)
{
	int i;
	double min = vect[0];
	for (i = 0; i < sizeof(vect); i++) //going through every row
	{
		if (vect[i] < min)
		{
			min = vect[i];
		}
	}
	return(min);
}
};

class Mean{
	public:
//calculate the mean 
float calcMean(vector<double>& vect)
{
	double mean = 0;
	int i;
	for (i = 0; i < sizeof(vect); i++) //going through every row
	{
		mean += vect[i];
	}
	mean = mean / sizeof(vect);
	return(mean);
}
};

class Std{
	public:
//calculating the standard deviation
double calcSd(vector<double>& vect) {
//double calcSd(double array[]) {
	int i;
	float result = 0.0;
	Mean calc; //create instance of mean class
	float m = calc.calcMean(vect);
	for (i = 0; i < sizeof(vect); i++)
	{
		result += pow((vect[i] - m), 2);
	}
	return sqrt(result / sizeof(vect)); //return the standard deviation
}
};

class Histogram{
	public:
	double calcHist(vector<double>& vect){
	//double calcHist(double array[]){ //input array
		//bin center should be at the mean
		Mean calc; //create instance of mean class
		double bin_center[] = {calc.calcMean(vect)};

		//find max of data
		Max calc_max;
		double max = calc_max.calcMax(vect);

		//find min of data
		Min calc_min; 
		double min = calc_min.calcMin(vect); 

		//get standard deviation
		Std calc_std; 
		double std = calc_std.calcSd(vect);

		//each bin should have a width of 0.4*sample standard deviation
		double bin_width = 0.4 * std; 

		//bins should begin and end at sample mean ±3*(sample stddev), respectively.
		double bin_start = 0.3*std, bin_end =(-0.3)*std; 

		//vector<int>binedge;
		int binedge[]={}; //array for binedge
		binedge[0]=bin_start; //set the first edge to the bin start
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
};