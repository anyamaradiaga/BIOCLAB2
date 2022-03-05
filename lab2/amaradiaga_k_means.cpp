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

std::ifstream FILE_1, FILE_2; //for the two files
std::ofstream expressed_file, suppressed_file, stationary_file; //define the output variables for files

kMean::cluster::cluster(){
    this->name;
    this->mean=0;
    this->distance=0;
    this->cluster_data;
}

void kMean::cluster::set_cluster_mean(float data){
    this->mean=data;
}

float kMean::cluster::get_cluster_mean(){
    return this->mean;
}

void kMean::cluster::set_distance(float data){
    this->distance= abs(data - this->mean);
}

float kMean::cluster::get_distance(){
    return this->distance;
}

void kMean::cluster::set_name(std::string name1){
    this->name=name1;
}

std::string kMean::cluster::get_name(){
    //this->name=name;
    return this->name;
}

int main(int argc, char** argv){
    MySpace::MyClass calc; 

    std::string log_ratio_file, gene_list_file; 
    kMean::cluster expressed_cluster, stationary_cluster, suppressed_cluster; 

    /*--------------------------------*/
    float suppressed_cluster_mean= -0.5; 
    float stationary_cluster_mean=  0;
    float expressed_cluster_mean=  0.5;
    /*--------------------------------*/

    gene_list_file="gene_list.txt"; 

    if(argv[1]!=NULL){
        log_ratio_file=argv[1];
    }
    else{
        std::cout<<"***No input file!***\n";
            return 1;
    }  
    FILE_1.open(log_ratio_file);      
    FILE_2.open(gene_list_file);

    if((FILE_1.is_open())&&(FILE_2.is_open())){ //correct way to check if file is opened
        std::istream_iterator<float> start_file1(FILE_1), end1;   //iterator helps get data from files
        std::vector<float> data_file1(start_file1, end1); 
        std::istream_iterator<std::string> start_file2(FILE_2), end2;   
        std::vector<std::string> data_file2(start_file2, end2);

        std::vector<float> cluster_1, cluster_2, cluster_3;
        std::vector<float> expressed, stationary, suppressed;

        float expressed_distance, stationary_distance, suppressed_distance;
        float new_cluster_mean1, new_cluster_mean2, new_cluster_mean3;
        float criteria=1;

        while(criteria>0.0001){
            //clearing clusters
            cluster_1.clear(), cluster_2.clear(), cluster_3.clear(), expressed.clear(), stationary.clear(), suppressed.clear();
            for(int j=0;j<data_file1.size();j++){
                
                /*expressed lot*/
                expressed_cluster.set_cluster_mean(expressed_cluster_mean);         
                expressed_cluster.set_distance(data_file1[j]);
                expressed_distance = expressed_cluster.get_distance();

                /*stationary lot*/
                stationary_cluster.set_cluster_mean(stationary_cluster_mean);        
                stationary_cluster.set_distance(data_file1[j]);
                stationary_distance = stationary_cluster.get_distance();

                /*suppressed lot*/
                suppressed_cluster.set_cluster_mean(suppressed_cluster_mean);        
                suppressed_cluster.set_distance(data_file1[j]);
                suppressed_distance = suppressed_cluster.get_distance();

                if((suppressed_distance<stationary_distance)&&(suppressed_distance<expressed_distance)){    
                    if(cluster_1.size()==0){
                        cluster_1.insert(cluster_1.begin(), data_file1[j]);
                        suppressed.insert(suppressed.begin(),j);
                    }
                    else{
                        vector<float>::iterator testing1= cluster_1.insert(cluster_1.end(), 1, data_file1[j]);    
                        vector<float>::iterator testing4= suppressed.insert(suppressed.end(), 1, j);    
                    }

                }
                else if((stationary_distance<=suppressed_distance)&&(stationary_distance<=expressed_distance)){     
                    if(cluster_2.size()==0){ 
                        cluster_2.insert(cluster_2.begin(), data_file1[j]);
                        stationary.insert(stationary.begin(),j);
                    }
                    else{
                        vector<float>::iterator testing2 = cluster_2.insert(cluster_2.end(), 1, data_file1[j]);    
                        vector<float>::iterator testing5 = stationary.insert(stationary.end(), 1, j);    

                    }
                }
                else{
                    if(cluster_3.size()==0){                                 
                        cluster_3.insert(cluster_3.begin(), data_file1[j]);             
                        expressed.insert(expressed.begin(),j);                            
                        //printf("**SORT3: **\n");
                    }
                    else{
                        vector<float>::iterator testing3 = cluster_3.insert(cluster_3.end(), 1, data_file1[j]);    
                        vector<float>::iterator testing6 = expressed.insert(expressed.end(), 1, j);    
                    }
                }  
            }

            /*------------------------------*/
            calc.calcMean(cluster_1);
            new_cluster_mean1 = calc.getMean();
            calc.calcMean(cluster_2);
            new_cluster_mean2 = calc.getMean();
            calc.calcMean(cluster_3);
            new_cluster_mean3 = calc.getMean();
            /*------------------------------*/

            criteria = abs(suppressed_cluster_mean - new_cluster_mean1) + abs(stationary_cluster_mean - new_cluster_mean2) + abs(expressed_cluster_mean - new_cluster_mean3);
                    
            expressed_cluster_mean = new_cluster_mean3;
            stationary_cluster_mean = new_cluster_mean2;
            suppressed_cluster_mean = new_cluster_mean1; 
        }

        /* ----------------------------------------------------------------- */
        printf("***Expressed Cluster Mean: %f***\n", expressed_cluster_mean);
        printf("***Stationary Cluster Mean: %f***\n", stationary_cluster_mean); 
        printf("***Suppressed Cluster Mean: %f***\n", suppressed_cluster_mean);    
        /* ----------------------------------------------------------------- */

        //opened file for writing 
        expressed_file.open("expressed_genes.txt");
        stationary_file.open("stationary_genes.txt");
        suppressed_file.open("suppressed_genes.txt");

        int x=0,y=0, w=0;
    
        for (int z=0; z<data_file1.size(); z++){      
            if(z==expressed[x]){                
                expressed_file<<data_file2[z]<<"\n";
                x++;
            }
            else if(z==suppressed[y]){         
                suppressed_file<<data_file2[z]<<"\n";
                y++;
            }
            else if(z==stationary[w]){          
                stationary_file<<data_file2[z]<<"\n";
                w++;
            }
        }

        //close all files
        expressed_file.close();    
        suppressed_file.close();
        stationary_file.close();

    }

    //cant open?---
    else{                           
        if(!(FILE_1.is_open())){                               
            std::cout<<"**NO DAT FILE!**\n";
            return 1;
        }
    }
    return 0;
}


    



