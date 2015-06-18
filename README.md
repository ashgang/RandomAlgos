# RandomAlgos
This repo contains all the random programs and algorithms that I try to learn.  The Python folder contains short programs written when learning python.
The root folder consists of mostly algos and other programs implemented in C and compiled and tested in Linux.  Some programs have a real story behind why it was written, that which you can read and enjoy below.

1. expr\_eval.c - This is a short program for expression evaluation using two stacks.  Run the program and check for how the input should be given.
	- During my bachelor's, for the C course this was the program I had to write for final practicals evaluation.  Unfortunately those were days I wasn't much interested in programming, and I somehow managed to get the output.  After years of being a sw engg, I thought I must write this program to see how easy it is to write it now.  And hence the program.
2. Below are the programs that were written when I had doubts that I forgot the basics.  These programs remind me that I still remember some basic stuff, and give me a chance to look back, if I ever feel that I forget the basics. 
(Hey to forget is human... if you don't forget stuff once in a while... hmmmm... you are a bot!)
	- basicLnLst.c
	- fnPtrUsage.c
	- queue_lnlst.c
	- semThdEg.c
	- stack_arrays.c
	- thisPtrUsage.cpp
	- basicTh.c - First thread program I wrote after eons!
	- basicFork_ChdOrph.c - Check the program comments for some information
	- basicFork_ParentWaitin.c - Check the program comments for some information
	- LinearSearch.c - Linear search implementation.  It takes O(1) best case and O(n) worst case running times
	- sortinAlg.c - Implements some searching algorithms, to be compiled as library and link with other programs that require sorting as intermediate step.
	- binarySearch.c - Binary search implementation. It takes O(1) best case and O(log n) worst case running times.  Note that
	you have to compile "sortinAlg.c" first as a library and link it to binary search when compiling it.  This search uses sorting algo's from the lib.
	To make task easy there is a makeLibrary.sh file, the usage is as below:
		- Step 1: ./makeLibrary.sh sortAlgos sortinAlg.c
		- Step 2: gcc binarySearch.c  -lsortAlgos -L./libs
		- ./a.out
	As you may see, the library will be put to ./libs folder and intermediate files will be put to ./interFiles folder.  So make sure these are available.

