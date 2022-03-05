/*
- Name: Anya Maradiaga
- Date: 15/02/22
- Description: ----
*/
#include "amaradiaga_pre_processing.hpp"

PreProcessing::MyProcess::MyProcess(){
    this->log_ratio;
}

//log ratio getter
vector<float> PreProcessing::MyProcess::get_log_ratio(){
    return this->log_ratio; 
}

void PreProcessing::MyProcess::set_log_ratio(vector<float> data, vector<float> data2){
    float count[data.size()];//count array
    for(int i=0; i<data.size();i++){
        count[i]=log10(data[i]/data2[i]); //get log ratio and put in array
        vector<float>::iterator testing2= this->log_ratio.insert(log_ratio.begin(), 1, count[i]); //load the values  
    }

}