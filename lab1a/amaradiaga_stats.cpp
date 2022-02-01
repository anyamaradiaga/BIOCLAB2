/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#include "amaradiaga_stats.hpp"

//calculating the maximum
double calcMax(double new_array[], int numrows)
{
	int i;
	double max = new_array[0];
	for (i = 0; i < numrows; i++) //going through every row
	{
		if (new_array[i] > max)
		{
			max = new_array[i];
		}
	}
	return(max);
}

//calculating the minimum
double calcMin(double new_array[], int numrows)
{
	int i;
	double min = new_array[0];
	for (i = 0; i < numrows; i++) //going through every row
	{
		if (new_array[i] < min)
		{
			min = new_array[i];
		}
	}
	return(min);
}

//calculate the mean 
float calcMean(double new_array[], int numrows)
{
	double mean = 0;
	int i;
	for (i = 0; i < numrows; i++) //going through every row
	{
		mean += new_array[i];
	}
	mean = mean / numrows;
	return(mean);
}

//calculating the standard deviation
double calcSd(double new_array[], int numrows) {
	int i;
	float result = 0.0;
	float m = calcMean(new_array, numrows);
	for (i = 0; i < numrows; i++)
	{
		result += pow((new_array[i] - m), 2);
	}
	return sqrt(result / numrows); //return the standard deviation
}