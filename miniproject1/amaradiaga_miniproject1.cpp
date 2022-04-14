/*
Name: Anya Maradiaga
Date: April 13, 2022
Description: This is the cpp that will calculate the statistics of airspeed velocity of European swallows
*/
#include "/home/maradia/BIOCLAB2/lab1a/amaradiaga_stats.cpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace StatsSpace;
std::ifstream file;

int main(int argc, char** argv){
    
    //getting name of input file
    std::cout <<"Enter file from swallowspeed.dat : ";
    std::string filename;
    std::cin >> filename;
    
    //opening file
    file.open(filename);

    if(file.is_open()){
        std::istream_iterator<float> start(file), end; //data from file
        vector<float> data(start, end);

    if(data[0]==NULL){ //error checking
        std::cout<<"El archivo esta vacío\n";
        return 1;
    }

    StatsSpace::StatsClass stats_data;

    stats_data.calcMax(data);
    float max = stats_data.getMax();
    cout<<"maximum value is: "<< max <<"\n";

    stats_data.calcMin(data);
    float min = stats_data.getMin();
    cout<<"minumum value is: "<< min <<"\n";

    stats_data.calcMean(data);
    float mean = stats_data.getMean();
    cout<<"average value is: "<< mean <<"\n";

    stats_data.calcSd(data);
    float stdv = stats_data.getSd();
    cout<<"standard deviation value is: "<< stdv <<"\n";
    }

    else{//error check
        cout<<"El archivo no pudo ser abierto\n";
        return 2;
    }

    return 0;
}


