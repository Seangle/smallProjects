#Sam van den Eijnden
#A REALLY simple quadratic calculator
#to assist in learning python

import math
#using python 2
print "Quadratic Root Calculator"
print "Enter the coefficients (format AX^2 + BX + C)"
#get user input
A = raw_input('AX^2:')
A = int(A)
B  = raw_input('BX:')
B = int(B)
C = raw_input('C:')
C = int(C)
#only calculate stuff under the root once
D = (B * B) - (4 * A * C)
if  ( D < 0 ):
	#negative root, not able to get with math.sqrt
	print "Sorry mate, negative root. The math library is not a fan."
else:
	#positive root(s)
	x1 = (-B + math.sqrt(D) )/ (2 * A)
	x2 = (-B - math.sqrt(D) )/ (2 * A)
	print "root 1: ", x1
	#check for repeated root
	if(x1 != x2):
		print "root 2: ", x2
