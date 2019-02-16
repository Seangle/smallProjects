/* Sam van den Eijnden
 * A simple bubble sort I made
 * While waiting on my friends to finish their other work
 * February 15th, 2019
 */
#include <stdio.h>

int main(){
	int i, j;
	int temp = 0;
	int numArray[15] = {8,10,42,1,96,54,22,88,51,62,42, 88, 100, 3, 29};
	
	/*Print the initial array*/
	printf("initial array: ");
	for(i = 0; i < 15; ++i){
		printf("%d ", numArray[i]);
	}
	printf("\n");
	
	/*Bubble Sort*/
	for(i = 0; i < 15; ++i){
		for(j = i; j < 15; ++j){
			/*Swap spots in array*/
			if(numArray[j] < numArray[i]){
				temp = numArray[i];
				numArray[i] = numArray[j];
				numArray[j] = temp;
			}
		}
	}
	
	/*Print sorted array*/
	printf("sorted array: ");
	for(i = 0; i < 15; ++i){
		printf("%d ", numArray[i]);
	}
	printf("\n");
	
	return 0;
}
