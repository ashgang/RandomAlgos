class helloWorld():
	def __init__(self):
		self.data = "Hello"

	def func(self):
		return self.data + " World"
	
	def outStr(self, oStr):
		print oStr

def doIt():
	ob = helloWorld()
	greet = ob.func()
	ob.outStr (greet)

if __name__ == "__main__":
	doIt()
	"""
	ob = helloWorld()
	greet = ob.func()
	ob.outStr (greet)
	"""
