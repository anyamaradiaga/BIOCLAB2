#Name: Anya Maradiaga
#Date: 01/25/22
#Description: 

#part 3 - intro to bash scripting to count all files/directories
#use find command to get to home directory, then specify that you only want files (including hidden)
#and pipe it to the wc command to count number of files with 1 entry per line. 

find $HOME -type f | wc -l




