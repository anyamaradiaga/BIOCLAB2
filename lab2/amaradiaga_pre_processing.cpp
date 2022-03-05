/*
- Name: Anya Maradiaga
- Date: 15/02/22
- Description: This is the file for preprocessing 
*/
#include "amaradiaga_pre_processing.hpp"
#include "amaradiaga_vector_ops.hpp"

int main (int argc, char* argv[]) {
    ifstream FILE1(argv[1]), FILE2(argv[2]), FILE3(argv[3]), FILE4(argv[4]); //file red sporulating cells 
    vector<float> red_data, background_red_data, green_data, background_green_data;
    fstream FILE5; // file for writing calibrated 
    FILE5.open(argv[5]);
    int argNum = atoi(argv[6]); 

    // verify that all files exist and make sure the number of genes requested in within bounds
    if (!FILE1.is_open() || !FILE2.is_open() || !FILE3.is_open() || !FILE4.is_open() || !FILE5.is_open()) {
        printf("No open data files...\n");
        return 0;
    }
    else if (argNum > 6118) {
        printf("Number of points is larger than expected...\n");
        return 0;
    }

    //fill redData vector with file data points
    float temp;
    while (FILE1 >> temp) {
		  red_data.push_back(temp);
    }
    FILE1.close();

    //fill background_redData vector with file data points
    while (FILE2 >> temp) {
		  background_red_data.push_back(temp);
    }
    FILE2.close();

    //fill greenData vector with file data points
    while (FILE3 >> temp) {
      green_data.push_back(temp);
    }
    FILE3.close();

    //fill background_greenData with file data points
    while (FILE4 >> temp) {
		  background_green_data.push_back(temp);
    }
    FILE4.close();

    MySpace::MyClass obj;// I tried using the namespace and class from the vector ops file but it didnt work...

    //Subtract the corresponding background intensities from the red and green datasets.
    vector<float> correct_red = obj.calcSub(&red_data, &background_red_data);
    vector<float> correct_green = obj.calcSub(&green_data, &background_green_data);

    //Calculate the means of the corrected datasets
    float red_mean = obj.calcSum(&red_data) / argNum;
    float green_mean = obj.calcSum(&green_data) / argNum;

    //Normalize the corrected green/red data by the green/red dataset mean
    vector<float> normal_red = obj.calcDiv(&correct_red, red_mean);
    vector<float> normal_green = obj.calcDiv(&correct_green, green_mean);

    //Write the log intensity ratio to the file specified in the input arguments
    for (int i = 0; i < argNum; i++) {
        FILE5 << std::log10(normal_red[i] / normal_green[i]) << "\n";
    }
    FILE5.close();

    return 0;

}