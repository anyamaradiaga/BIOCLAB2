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
double calcMax(double array[])
{
	int i;
	double max = array[0];
	for (i = 0; i < sizeof(array); i++) 
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return(max);
}
};


//calculating the minimum
class Min{
	public:
double calcMin(double array[])
{
	int i;
	double min = array[0];
	for (i = 0; i < sizeof(array); i++) //going through every row
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return(min);
}
};

class Mean{
	public:
//calculate the mean 
float calcMean(double array[])
{
	double mean = 0;
	int i;
	for (i = 0; i < sizeof(array); i++) //going through every row
	{
		mean += array[i];
	}
	mean = mean / sizeof(array);
	return(mean);
}
};

class Std{
	public:
//calculating the standard deviation
double calcSd(double array[]) {
	int i;
	float result = 0.0;
	Mean calc; //create instance of mean class
	float m = calc.calcMean(array);
	for (i = 0; i < sizeof(array); i++)
	{
		result += pow((array[i] - m), 2);
	}
	return sqrt(result / sizeof(array)); //return the standard deviation
}
};

class Histogram{
	public:
	double calcHist(double array[]){ //input array
		//bin center should be at the mean
		Mean calc; //create instance of mean class
		double bin_center[] = {calc.calcMean(array)};

		//find max of data
		Max calc_max;
		double max = calc_max.calcMax(array);

		//find min of data
		Min calc_min; 
		double min = calc_min.calcMin(array); 

		//get standard deviation
		Std calc_std; 
		double std = calc_std.calcSd(array);

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
		for(int i=0; i<= sizeof(array);i++){
			for( int j=bin_start; j<=bin_end; j++){
				if(array[i] < binedge[j + 1] && binedge[j] <= array[i]){
					count ++;
				}
			}
			count_array[i] = count; //array that stores the count total
		}
		return(count);
	}
};