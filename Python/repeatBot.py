"""
This program repeats whatever the user types.
To exit the program user has to say 'bye'
"""

print "Welcome to RepeatBot 1.0"
print "Wish you have a great time"
print "I will repeat anything that you say, until you tell me bye"

while True:
	line = raw_input(">> ")
	if line == "Bye" or line == "bye" or line == "BYE":
		print "Hope you had a happy time with RepeatBot 1.0. Bye!!!"
		break
	else:
		print line
