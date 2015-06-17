#!/bin/bash

flag=0

if [ "$1" ==  "-h" ]; then
	echo "Usage: .makeLibrary <lib_name> <file1.c> <file2.c> ...."
	echo "Both .so and .a will be created"
	flag=0
elif [ "$#" -lt 2 ]; then
	echo "Provide the args or type <script_name> -h for help"
	flag=0
else
	echo "*******************************************************************************************************************************"
	echo "||Starting make with all the args you provided! If any of your args are incorrect, it may kill your cat and destroy your home||"
	echo "*******************************************************************************************************************************"
	flag=1
fi

if [ $flag == 1 ]; then
	for var in ${@:2}
	do
		gcc -c $var
		var=$(sed  's/\.c/\.o/g' <<< $var)
		mv $var ./interFiles/$var
		echo $var
		ar -cr ./libs/lib$1.a ./interFiles/$var
	done
	echo "********************************************************************************************"
	echo "|| Please find the library in ./libs folder and intermediate files in ./interFiles folder ||"
	echo "********************************************************************************************"

else
	echo "Something's wrong exiting"
fi

