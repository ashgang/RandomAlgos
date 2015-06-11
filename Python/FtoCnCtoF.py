import random #For random generation library
import math #For Maths functions

def userInput():
	temp_dec = raw_input("Want to convert from Fahrenheit to celsius (F/f) or celsius to Fahrenheit (C/c) or enter bye to exit?")
	return temp_dec

def convFtoC(valFar):
	print "Value in Fahrenheit: " + str(valFar)
	valCel = (valFar - 32) * (5.0/9.0)
	return valCel
	
def convCtoF(valCel):
	print "Value in Celsius: " + str(valCel)
	valFah = (valCel * (9.0/5.0)) + 32
	return valFah

while 1:
	temp_dec = userInput()
	if temp_dec is 'F' or temp_dec is 'f':
		print "You have requested a conversion from Fahrenheit to celsius\n"
		tempInF = raw_input("Enter temperature in Fahrenheit: ")
		valInCel = convFtoC(int(tempInF))
		print "Value in Celsius: %g" % valInCel
	elif temp_dec is 'C' or temp_dec is 'c':
		print "You have requested a conversion from celsius to Fahrenheit\n"
		tempInC = raw_input("Enter temperature in Celsius: ")
		valInFah = convCtoF(int(tempInC))
		print "Value in Fahrenheit: %g" % valInFah
	elif temp_dec == 'bye' or temp_dec == 'Bye':
		print "Bye! see you again!!!"
		break
	else :
		print "Wrong selection! select again\n"

