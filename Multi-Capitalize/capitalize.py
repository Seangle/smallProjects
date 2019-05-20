#Sam (Sean) van den Eijnden
#Capitalize the first letter of every word in a string of words
#Python 3.6.7
#February 18th, 2019

#prompt user for a string of words
text = input("Enter a string of words: ")

#Split Strings by spaces. Other cases can be added. Example included
#words.replace(',', ' ') #uncomment to add punctuation case for ','. other cases can be added
words = text.split()
newString = ""
#loop through each word that was split
for words in words:
	#capitalize the word
	words = words.capitalize()
	#Add the string to the new string
	newString += words + " "
#print the result
print(newString)
