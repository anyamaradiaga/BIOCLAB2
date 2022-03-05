#!/bin/sh
#------------------------------------------------------------------------------------------------------------
# Name: Anya Maradiaga 
# Due Date: March 4, 2022
# Description: This file contains the script to help the user probe the expression sequence of specified gene
#------------------------------------------------------------------------------------------------------------

echo "hello please select gene: "

read userin

#read in everything 

if grep -Fxq "$userin" "expressed_genes_total_"$1".txt" #check userin
then
    echo "expressed"
else
    if grep -Fxq "$userin" "suppressed_genes_total_"$1".txt"  #check userin
    then
        echo "suppressed"
    else
        if grep -Fxq "$userin" "stationary_genes_total_"$1".txt"  #check userin
        then
            echo "stationary"
        else                       
            echo "failed to select correct gene"
        fi
    fi
fi

