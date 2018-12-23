/*
Sam van den Eijnden
Fibonacci sequence generator
*/

#include <stdio.h>	/*For output to console*/
#include <string.h>	/*For checking flags*/
#include <stdlib.h> /*convert number to strings*/
#include <time.h>	/*For measuring time*/

/*
TODO: writing to a file
Flags:
	'-w' flag for writing to a file
	'-t" flag for showing time taken to calculate
	'-n #'flag for number limit, where # is the number
Current limit: unsigned long limit on laptop (64-bit) is around 9,700,000,000,000,000,000 in ANSI standard
Status: Works, no file write
*/

int main(int argc, char **argv){
	
	/*Clock variables*/
	clock_t start_t, end_t, total_t;
	double totalTime;
	
	/*Calculator variables*/
	unsigned long a = 0;
	unsigned long b = 1;
	unsigned long c;
	int i = 0;
	unsigned long numberLimit = 9000000000000000000;
	
	/*Flag variables*/
	int temp;
	int flags[2];
	
	/*Checks flags*/
	for(temp = 0; temp < argc; temp++){
		/*write to file*/
		if(strcmp(argv[temp],"-w")==0) flags[0] = 1;
		/*Time the calculation*/
		if(strcmp(argv[temp],"-t")==0) flags[1] = 1;
		/*change number limit*/
		if(strcmp(argv[temp],"-n")==0){
			numberLimit = atoi(argv[temp+1]);
		}
	}
	
	printf("Fibonacci Sequence generator\n");
	
	if(flags[1]==1)start_t = clock();
	
	/*Fibonacci  Sequence Calculator*/
	while(c < numberLimit || i < 101){
		printf("%lu\n", c);
		c = a + b;
		a = b;
		b = c;
		++i;
	}
	
	if(flags[1]==1)end_t = clock();
	
	/*Clock printouts*/
	if(flags[1]==1){
		total_t = (end_t - start_t);
		printf("Total clocks to calculate: %li\n", total_t);
		printf("clocks per second: %li\n", CLOCKS_PER_SEC);
		totalTime = ((double) total_t / (double) CLOCKS_PER_SEC);
		printf("Total time to calculate: %f seconds\n", totalTime);
	}
	return 0;
}
