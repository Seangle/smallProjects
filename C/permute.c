/* Sam van den Eijnden
 * January 13th, 2019
 * prints all possible permutations of the characters in a word
 * Modified version of my school work to work for more words.
 * */

#include <stdio.h>
#include <string.h>

/*function prototypes*/
void permute(char *word);
void recursiveCharacters(char *word, int index);
void swap(char *a, char *b);

/*function definitions*/
int main(int argc, char** argv){
	if(argc == 1){
		printf("Not enough arguments. format is \"./permute <word_to_be_permutated>\".\n");
	} else if(argc >= 3) {
		printf("Too many arguments. format is \"./permute <word_to_be_permutated>\".\n");
	} else {
		permute(argv[1]);
	}
	return 0;
}

/* gets called from main, starts the recursive function
 * could also be called from an external function call in the future*/
void permute(char *word){
	recursiveCharacters(word, 0);
	return;
}

/*get every permutation of the word using recursion*/
void recursiveCharacters(char *word, int index){
	int i;
	int end = strlen(word) - 1;
	/*check if each character has been swapped*/
	if(index != end){
		for(i = index; i <= end; ++i){
			/*swap characters for a new combination*/
			swap(word + index, word + i);
			/*call the recursive function, increment the index*/
			recursiveCharacters(word, index + 1);
			/*swap the characters back so it doesn't mess up later combinations*/
			swap(word + index, word + i);
		}
	} else {
		/*print the word once 6 letters have swapped*/
		/*printWordTest(word);*/
		printf("%s\n", word);
	}
	return;
}

/*Fairly standard swap function for strings*/
void swap(char *a, char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

