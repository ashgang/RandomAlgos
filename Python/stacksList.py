"""
This program implements the stacks data structure,
using Lists in python
List when modified will be same across functions so its not returned
We can directly use append() for inserting and pop() for popping out.
This is done just to show reverse order and for learning purposes.
"""
#Pushing in stack
def pushItem(iList, item):
	iList.insert(0,item)

#Popping from stack
def popItem(iList):
	pItem = None
	if len(iList) == 0:
		print "Nothing to pop!"
	else:
		pItem = iList.pop(0)
	return pItem

#Deleting the stack
def delStack(iList):
	if len(iList) == 0:
		print "List empty!"
	else:
		del iList[:len(iList)]

#This function creates list from the parameter passed; here it makes an empty list
iList = list()
while True:
	uChoice = raw_input("1. Push\n 2. Pop \n 3. Delete \n 4. Exit \n Enter your choice:")	
	if uChoice == '1':
		uItem = raw_input("Enter the item to be pushed:")
		pushItem(iList, uItem)
		print iList
	elif uChoice == '2':
		pItem = popItem(iList)
		print "Item poped is:", pItem
		print iList
	elif uChoice == '3':
		delStack(iList)
		print iList
	elif uChoice == '4':
		exit()
	else:
		print "Wrong choice! Exiting..."
		exit()
