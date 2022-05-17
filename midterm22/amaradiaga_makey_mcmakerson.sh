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

DIR_PATH=$1
FILE="Makefile"
makefile="$DIR_PATH/$FILE"

touch makefile

echo "CC=g++" > makefile

for d in midterm22/*/ ; do
    folder_name="${d#$DIR_PATH}"
    folder_name="${folder_name::-1}"
    
    printf "\n" >> $makefile #print new line
    printf "\n" >> $makefile #print new line
    
    #.o files into makefile
    echo -n "$folder_name.o:" >> $makefile

    #WRITE CPP AND HPP FILES in makefile:
    count_mains=0 #setting count for mains
    #echo $folder_name
    for p in $d* ; do
        #this will get the directory for the filename
        myFile="${p#$DIR_PATH}"
        echo -n " $myFile" >> $makefile
        #search for every file line tthe main
        if grep -q "main" $p; then
            if cat $p | sed -n '/\/\*/, /\*\//p' | grep -q "main"; then
                ignore_array+=("${main_file}")
            else
                count_mains=$((count_mains+1))
                #check the count
                if [ $count_mains -lt 2 ]
                then
                    main_file="${p##*/}"
                    main_file="${myFile::-4}"
                    main_array+=("${main_file}")
                else    
                    temp+=("${myFile}")
                    #echo "${myFile}"
                fi 
            fi
        fi
done
    #non exes 
    printf "\n\t" >> $makefile
    echo "\$(CC) -c $^" >> $makefile
    printf "\n" >> $makefile
    echo -n "${folder_name}_exec:" >> $makefile
    #this is the array that will contain all the exes
    exes+=("${folder_name}_exec")
    for p in $d* ; do
        myFile="${p#$DIR_PATH}"
        # echo $myFile
        #checking whether the file is a cpp file
        if [[ $myFile == *.cpp ]]; then
            # echo $myFile
            if [[ ! " ${temp[*]} " =~ " $myFile " ]]; then
            myFile="${myFile::-4}"
            myFile="${myFile}.o"
            #echo $myFile
            echo -n " $myFile" >> $makefile
            fi
        fi
    done
    printf "\n\t" >> $makefile
    echo "\$(CC) -o \$@ \$^" >> $makefile
done

#ALL
printf "\n" >> $makefile
echo -n "all:" >> $makefile
for value in "${exes[@]}"
do
     echo -n " $value" >> $makefile
done
#CLEAN
printf "\n" >> $makefile
echo "
clean:" >> $makefile
for d in midterm2022/*/ ; do
    folder_name="${d#$DIR_PATH}"
    folder_name="${folder_name::-1}"
    printf "\t" >> $makefile
    echo "rm -f $folder_name/*.o" >> $makefile
    printf "\t" >> $makefile
    echo "rm -f $folder_name/*.gch" >> $makefile
    printf "\t" >> $makefile
    echo "rm -f ${folder_name}_exec" >> $makefile
done

cd ${DIR_PATH}
make all

for value in "${exes[@]}"
do
     ./$value
done

#exe=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2 | cut -d '.' -f1 | sed 's/.cpp/.o/g'))
#cppo=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2 | cut -d '.' -f1))
#hppo=($(grep -rl --include=*.cpp ./ | cut -d '/' -f2 | cut -d '.' -f1 ))

#length= echo ${#exes[@]}
#cpplength= echo ${#cppfiles[@]}
#hpplength= echo ${#hppfiles[@]}


