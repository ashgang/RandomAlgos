"""
This program is to describe lists in python
"""
cheeseVar = ["Chedar", "American", "Parmesan", "Edam", "Gouda"]

print "These are the cheese varieties available here:"
count = 1
for cheese in cheeseVar:
	print "%d) %s" % (count, cheese)
	count = count + 1
