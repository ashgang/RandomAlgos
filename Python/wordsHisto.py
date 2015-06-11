"""
This program is essentially to create a histogram of the words,
from a user given file and present it in a dictonary form
"""
import string

fFileName = raw_input("Enter the file name:")
try:
	fHandle = open(fFileName)
except:
	print "File opening failed!"
	exit()

wordCount = dict()
for line in fHandle:
	line = line.rstrip() #Since we are only spliting this does not make any difference
	line = line.translate(None, string.punctuation)
	line = line.lower()
	words = line.split()
	for word in words:
		if word not in wordCount:
			wordCount[word] = 1
		else:
			wordCount[word] += 1
print "============This is the unsorted list==============="
print wordCount
#This is done to list the keys in alphabetical order
#+++++++SORTED LIST IS DISABLED NOW++++++++
#"""
keyList = wordCount.keys()
keyList.sort()
print "============This is the sorted list==============="
for key in keyList:
	print key, "\t", wordCount[key]
#"""
