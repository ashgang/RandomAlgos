"""
This is python implementation of fibonacci series
Fibonacci series is done in a function and is returned 
as a list to the caller
"""

def fib(uCount = 10):
	a, b = 0, 1
	fibSer = list()
	while uCount > 0:
		#print a
		fibSer.append(a)
		a, b = b, a+b
		uCount -= 1
	print fibSer
	return fibSer

def fib2n(uCount = 10):
	a, b = 0, 1
	fibSer = list()
	while a < uCount:
		#print a
		fibSer.append(a)
		a, b = b, a+b
	print fibSer
	return fibSer

"""
uCount = int(raw_input("Enter the count of numbers for the series:"))
if uCount > 0:
	fibSer = fibo(uCount)
else:
	fibSer = fibo()
print fibSer
"""

if __name__ == "__main__":
	import sys
	fib(int(sys.argv[1]))
	fib2n(int(sys.argv[2]))
