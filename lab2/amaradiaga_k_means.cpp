/*
-------------------------------------------------------
- Name: Anya Maradiaga 
- Due Date: March 4, 2022
- Description: This file contains clustering techniques
-------------------------------------------------------
*/

#include "amaradiaga_stats.hpp"
#include "amaradiaga_vector_ops.hpp"
#include "amaradiaga_pre_processing.hpp"
#include "amaradiaga_k_means.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

//std::ifstream FILE_1, FILE_2; //for the two files
//std::ofstream expressed_file, suppressed_file, stationary_file; //define the output variables for files

kMean::cluster::cluster(string nameInput, float meanInput){
    this->name = nameInput;
    this->mean = meanInput;
}

void kMean::cluster::set_cluster_mean(vector<float> data){
    float mean = 0;
    float sum = 0;
    float size = data.size();
    for (int i = 0; i < size; i++) {
        sum+= data[i];
    }
    this->mean = sum / size;
}

float kMean::cluster::get_cluster_mean(){
    return this->mean;
}

float kMean::cluster::set_distance(float data){
    float dist = 0;
    dist = fabs(data- this->mean);
    return dist;
}

void kMean::cluster::set_name(std::string name1){
    this->name=name1;
}

std::string kMean::cluster::get_name(){
    //this->name=name;
    return this->name;
}

int main(int argc, char** argv){
    vector<float> cluster1_data, cluster2_data, cluster3_data, data;
    float criteria, temp;

    ifstream file1("intensity_0.dat"); //file that contains the data for red sporulating cells

    /*--------------------------------*/
    kMean::cluster cluster_1("suppressed", -0.5);
    kMean::cluster cluster_2("stationary", 0.0);
    kMean::cluster cluster_3("expressed", 0.5);
    /*--------------------------------*/

    float temp;
    while (file1 >> temp) { // fill vector from file
		data.push_back(temp);
    }
    file1.close();

     do {
        // fill clusters
        for (int i = 0; i < data.size(); i++) {
            // calculate distance from point to each cluster mean
            float d1 = cluster_1.set_distance(data[i]);
            float d2 = cluster_2.set_distance(data[i]);
            float d3 = cluster_3.set_distance(data[i]);

            // assign each point to the appropriate cluster
            if ((d1 <= d2) && (d1 <= d3)) {
                cluster1_data.push_back(data[i]);
            }
            else if (d2 <= d3) {
                cluster2_data.push_back(data[i]);
            }
            else {
                cluster3_data.push_back(data[i]);
            }
        }

        // get old cluster means
        float old_mean_c1 = cluster_1.get_cluster_mean();
        float old_mean_c2 = cluster_2.get_cluster_mean();
        float old_mean_c3 = cluster_3.get_cluster_mean();

        // set new cluster means using sorted data
        cluster_1.set_cluster_mean(cluster1_data);
        cluster_2.set_cluster_mean(cluster2_data);
        cluster_3.set_cluster_mean(cluster3_data);

        // calculate the criteria value by comparing the old mean to the new mean
        criteria = cluster_1.set_distance(old_mean_c1) + cluster_2.set_distance(old_mean_c2) + cluster_3.set_distance(old_mean_c3);

        // remove all data points from each cluster
        cluster1_data.clear();
        cluster2_data.clear();
        cluster3_data.clear();

    } while (criteria > 0.0001);
    
    // open gene_list.txt and create files to write to
    FILE* gene_list = fopen("gene_list.txt", "r");
    FILE* expressed = fopen("expressed_genes.txt", "w");
    FILE* suppressed = fopen("suppressed_genes.txt", "w");
    FILE* stationary = fopen("stationary_genes.txt", "w");
    int j = 0;

    if (gene_list != NULL) { // run while gene_list is open
        char gene[10];
        while (!feof (gene_list))
        {
            // establish values (basically redoing last loop of clustering)
            float point = data[j];
            float d1 = cluster_1.set_distance(point);
            float d2 = cluster_2.set_distance(point);
            float d3 = cluster_3.set_distance(point);
            fgets(gene, 10, gene_list); // get gene from gene_list, one line at a time
        
            // add gene to appropriate file
            if (d1 <= d2 && d1 <= d3) {
                fprintf(suppressed, "%s", gene);
            }
            else if (d2 <= d3) {
                fprintf(stationary, "%s", gene);
            }
            else {
                fprintf(expressed, "%s", gene);
            }
            j++;  
        }
        
        // close all files
        fclose(gene_list);
        fclose(suppressed);
        fclose(stationary);
        fclose(expressed);

        return 0;
    }
}


    



