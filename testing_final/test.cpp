/*
This loads csv files
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>

std::ifstream myfile;
std::string filename; 
 
using namespace std;
 
int main()
{
 	std::ifstream  data("AOsub_OS_confocal_0005_ref_132_lps_12_lbss_10_250um T_coords.csv");
	vector<vector<string>> content;
	//vector<string> row;
	string line, value;
 
	//fstream file (fname, ios::in);
	while(getline(data, line,'\n')){
	stringstream lineStream(line);

	//std::stringstream lineStream(line);
	std::string cell;
    std::vector<std::string> row;
    while(std::getline(lineStream,cell,',')){
            row.push_back(cell);
    }
	content.push_back(row);
    }
};







