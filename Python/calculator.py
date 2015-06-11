firstNo = raw_input("Enter first number:")
firstNo = int(firstNo)
secondNo = raw_input("Enter second number:")
secondNo = int(secondNo)
op = raw_input("Enter the operand:")

if op == '+':
	result = firstNo + secondNo
elif op == '-':
	result = firstNo - secondNo
elif op == '*':
	result = firstNo * secondNo
elif op == '/':
	result = firstNo / secondNo
else:
	result = "Illegal Operand!"

if type(result) is not int:
	print "Illegal Operand!"
else:
	print "The result is: " + str(result)
