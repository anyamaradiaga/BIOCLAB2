#!/bin/sh
#--------------------------------------------------------------------------------
# Name: Anya Maradiaga 
# Due Date: March 4, 2022
# Description: This file contains calibration and cluster for the microarray data
#--------------------------------------------------------------------------------

#take in user input...
echo "Please select time points [0-6]: "

read userin

#error checking...
while [ ! $userin == "0" ] && [ ! $userin == "1" ] && [ ! $userin == "2" ] && [ ! $userin == "3" ] && [ ! $userin == "4" ] && [ ! $userin == "5" ] && [ ! $userin == "6" ];
do
    echo "Try again"                       
    echo "The input wasn't a number between 0 and 6"
    read userin
done  

if [ $userin == "0" ]                  
then 
    second=0
fi

if [ $userin == "1" ]                  
then 
    second=1
fi

if [ $userin == "2" ]                   
then 
    second=2
fi

if [ $userin == "3" ]                   
then 
    second=3
fi

if [ $userin == "4" ]                  
then 
    second=4
fi

if [ $userin == "5" ]                   
then 
    second=5
fi

if [ $userin == "6" ]                  
    second=6
fi


data="datafiles/datafiles/"         #make the string variables
green="green_"
green_back="green_background_"
red="red_"
red_back="red_background_"
gene="gene_list.txt"
dat=".dat"
log_rat="log_ratio_"
index=0
input="input"
echo "summary file" > "overall_summary.txt"

while [ $index -le $second ]        
do
     ./preprocess $data$red$index$dat $data$red_back$index$dat  $data$green$index$dat  $data$green_back$index$dat $log_rat$index$dat $second
     cat $log_rat$index$dat > $log_rat$indput$dat       
       echo "this is time point #$index" >> "overall_summary.txt"       #print to file
       echo " "
       echo "time Stamp $index"
     ./cluster $log_rat$indput$dat >> "overall_summary.txt"     #run the cluster

        cat "expressed_genes.txt">"expressed_genes_total_"$index".txt"      #print to file
        cat "suppressed_genes.txt">"suppressed_genes_total_"$index".txt" 
        cat "stationary_genes.txt">"stationary_genes_total_"$index".txt" 

        echo "total number of expressed Genes: " >>"overall_summary.txt"           #print to file
        wc -l < "expressed_genes_total_"$index".txt" >>"overall_summary.txt"
        echo "total number of suppressed Genes:" >>"overall_summary.txt"
        wc -l < "suppressed_genes_total_"$index".txt" >>"overall_summary.txt"
        echo "total number of stationary Genes:" >>"overall_summary.txt"
        wc -l < "stationary_genes_total_"$index".txt" >>"overall_summary.txt"

        bash amaradiaga_genequery.sh "$index"            

    let "index++"
done

    
