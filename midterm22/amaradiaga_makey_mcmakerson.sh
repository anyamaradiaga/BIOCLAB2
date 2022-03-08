#!/bin/bash
#Name: Anya Maradiaga
#Date: 03/08/22
#Description: The following code creates the makefile for the cpp and hpp files in test folder

#check total number of arguments
echo "the passed arguments are:"
echo $@
echo "the total number of arguments is:"
echo $#

#check if directory path exists
if [ -d "$1" ]             
then
    echo "this path exists"
else
    echo "this path doesnt exist"
fi

IFS=" " read -r targets; do
    data[numrows] = $targets; 
    ((num_rows=num_rows+1))
done < "Straightforward/dandelion.cpp"

#we want to read variables that are between spaces but we also want to ignore "<<" and ":"

