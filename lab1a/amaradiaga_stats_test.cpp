/*
Name: Anya Maradiaga
Date: 02/01/22
Description: The following file tests the functions from amaradiaga_stats.cpp 
*/
#include "amaradiaga_stats.hpp"
//#include "amaradiaga_stats.cpp"

int main(){
    //should expect input argument with path of input data file.
    std::ifstream input_file;
    
    std::cout << "Enter the filename: " << endl;
    std::string filename;
    std::cin >> filename;
    filename.append(".txt");
    input_file.open( filename.c_str() );

    //checks that all data points are read properly
    //If the data file cannot be found, an error should be printed to the screen and data analysis should be terminated.
    if( !input_file.is_open() ){
      // If the file couldn't be opened:
      cout << "File couldn't be opened successfully!" << endl;
      return 1;
    }

    //show number of points being analyzed: 
    int n, total=0, count=0; 
    while ( !input_file.eof()){
        input_file>>n;
        total=total+n;
        count++;
    }
    cout<<"Number of points in file: "<<count<<endl;

    vector<double>data;
    for(int i = 0; i << input_file.eof(); i++){
        input_file >> data[i]; //store file data to array 
    }

    //find mean and then output 
    //Mean_Space::My_MeanSpace:: Mean cmean; 
    //double mean = cmean.calcMean(data);
    //cout <<"Mean: "<<mean;

    //find standard deviation
    //Std cstd;
    //double std = cstd.calcSd(data); 
    //cout <<"Standard Deviation: "<<std;

    //Find max
    //Max cmax; 
    //double max = cmax.calcMax(data);

    //Find min
    //Min cmin; 
    //min = cmin.calcMin(data); 

    //Output Histogram
}   
