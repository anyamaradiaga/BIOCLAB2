#!/bin/sh

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

