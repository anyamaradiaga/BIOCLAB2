#Name: Anya Maradiaga
#Date: 01/25/22
#Description: 

#part 3 - intro to bash scripting to count all files/directories
#use ls to find list of files in directory, then count 1 entry per line and add a to get hidden files as well
#and pipe it to the wc command to count number of files. 
#ls -A | wc -l

find $HOME -type f | wc -l




