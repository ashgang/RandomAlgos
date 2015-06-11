#All of this can be performed with inbuilt functions
#Basically this is an useless program, written only for 
#learning purposes

count = raw_input("Enter the number of values to be computed on:")
count = int(count)

#Here are the function declarations
def maximumNo(uList):
	largestNo = None
	for item in uList:
		if largestNo == None or largestNo < item:
			largestNo = item
	return largestNo

def minimumNo(uList):
	smallestNo = None
	for item in uList:
		if smallestNo == None or smallestNo > item:
			smallestNo = item
	return smallestNo

def sumOfList(uList):
	sumoflist = 0
	for item in uList:
		sumoflist = sumoflist + item
	return sumoflist

def countOfList(uList):
	countoflist = 0
	for item in uList:
		countoflist = countoflist + 1
	return countoflist

def average(uList):
	avg = 0
	for items in uList:

userList = []

#Getting the inputs
t = count
while t > 0:
	uip = raw_input("Enter number:")
	uip = int(uip);
	userList.append(uip)
	t = t - 1
print "The maximum no in the list is: " + str(maximumNo(userList))
print "The minimum no in the list is: " + str(minimumNo(userList))
print "The sum of nos in the list is: " + str(sumOfList(userList))
print "The count of nos in the list is: " + str(countOfList(userList))
print "Average of the list: " + str(average(userList))

print "Results from inbuilt functions"
print "The maximum no in the list is: " + str(max(userList))
print "The minimum no in the list is: " + str(min(userList))
print "The sum of nos in the list is: " + str(sum(userList))
print "The count of nos in the list is: " + str(len(userList))
