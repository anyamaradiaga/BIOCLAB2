#!/bin/bash
#Name: Anya Maradiaga
#Date: 03/08/22
#Description: The following code creates the makefile for the cpp and hpp files in test folder

#check total number of arguments
echo "the passed arguments are:"
echo $@
echo "the total number of arguments is:"
echo $#

userin=$1

#check if directory path exists
if [ userin ]             
then
    echo "this directory exists"
else
    echo "this directory doesnt exist"
fi

touch makefile

echo "CC=g++" > makefile

cppfiles=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2))

hppfiles=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2 | sed 's/.cpp/.hpp/g'))

#check main
if grep -Rl 'main' $f; then
    echo -e "main\n"
else
    echo -e "nooo main\n"
fi

declare -a exes=($(grep -rl --include=\*.cpp ./ | cut -d '/' -f2 | sed 's/.cpp/.o/g' ))

exe=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2 | cut -d '.' -f1 | sed 's/.cpp/.o/g'))
cppo=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2 | cut -d '.' -f1))
hppo=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2 | cut -d '.' -f1 ))

length= echo ${#exes[@]}
cpplength= echo ${#cppfiles[@]}
hpplength= echo ${#hppfiles[@]}

for((i=0; i<length; ++i)); do
  for((j=0; j<26; ++j)); do
    if [[ ${exe[i]} == ${cppo[j]} ]]; then

      echo "${exes[i]}" >> makefile
    fi
  done
done

