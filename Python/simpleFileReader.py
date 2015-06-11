"""
This is a simple file reader
And prints all the lines that starts with from:
"""
fName = raw_input("Enter the file name: ")
try:
	fhand = open(fName)
except:
	print "'%s' file does not exist!!!" % fName
	exit()
filWord = raw_input("Filter for line starting with word (Please provide the word. Note: its case sensitive)??")
dup_chk = raw_input("Remove duplicates (y/n)")

lCount = 0
lResults = ''
for line in fhand:
	lCount = lCount + 1
	#line = line.rstrip()
	if line.startswith(filWord):
		#Check for duplicates here
		if (dup_chk == 'y' or dup_chk == 'Y'):
			if lResults.find(line) == -1:
				lResults = lResults + line
		else:
			lResults = lResults + line
fopHand = open("output.txt", "w")
fopHand.write(lResults)
fopHand.close()
print lResults
print "Total number of lines in the file is %d" % lCount
