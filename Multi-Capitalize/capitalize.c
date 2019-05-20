/* Sam (Sean) van den Eijnden
 * Capitalize the first letter of every word in a sentence
 * C (ansi / std=c90)
 * Compiler: gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
 * February 18th, 2019
 * */
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	/*allocate space for 1024 characters. Dynamic memory allocation requires a lot more work.*/
	char input[1024];
	char *words;
	char output[1024] = "";
	
	/*prompt user imput*/
	printf("Enter a string of words: ");
	scanf("%[^\n]", input);
	
	/*split string using space as a delimiter. other delimiters can be added if needed.*/
	words = strtok(input, " ");
	
	/*loop through each word*/
	while(words != NULL){
		/*turn the first letter into its uppercase form*/
		words[0]  = toupper(words[0]);
		
		/* put resulting word into the ouput string*/
		strcat(output, words);
		strcat(output, " ");
		words = strtok(NULL, " ");
	}
	
	/*print the resulting output*/
	printf("%s\n", output);
	return 0;
}
