/*
Name: Anya Maradiaga
Date: 02/01/22
Description:
*/
#include "amaradiaga_stats.hpp"

int main(){
    //should expect input argument with path of input data file.
    string filename;
    ifstream input_file;
    int n, total=0, count=0; 
    cout << "Enter the filename: ";
    cin >> filename;
    input_file.open( filename.c_str() );

    //checks that all data points are read properly
    //If the data file cannot be found, an error should be printed to the screen and data analysis should be terminated.
    if( !input_file.is_open() ){
      // If the file couldn't be opened:
      cout << "File couldn't be opened successfully!" << endl;
      return 1;
    }

    //show number of points being analyzed: 
    while ( !input_file.eof()){
        input_file>>n;
        total=total+n;
        count++;
    }
    cout<<"Number of integers in file: "<<count<<endl;

}