/*
Sam van den Eijnden
Prime number generator
Current TODOs:
-write to file
*/

/*standard outpu*/
#include <stdio.h>
/*Timing*/
#include <time.h>
/*Check command line flags*/
#include <string.h>
/*Multithreading*/
#include <omp.h>

int bruteforceInt(long int checkNumber);
int fastbruteforceInt(long int checkNumber);
int formulaInt(int checkNumber);


int main(int argc, char **argv){
	
	/*Calculator option variables*/
	long int STARTING_POINT_CALC = 1;
	long int ENDING_POINT_CALC = 5000000;
	long int number;
	
	/*Thread variables*/
	int MULTITHREAD = 0;
	
	/*Clock Variables*/
	int NUM_OF_THREADS = 4;
	clock_t begin, end;
	double time_spent;
	
	/*Flag variables*/
	int temp;
	int flags[3];
	
	/*check flags*/
	for(temp = 0; temp < argc; ++temp){
		/*fast bruteforce*/
		if(strcmp(argv[temp], "-fast") == 0) flags[0] = 1;
		/*enable clock*/
		if(strcmp(argv[temp], "-time") == 0) flags[1] =  1;
		/*write to file TODO*/
		if(strcmp(argv[temp], "-write") == 0) flags[2] = 1;
		/*enable threading*/
		if(strcmp(argv[temp], "-thread") == 0) MULTITHREAD = 1;
		/*change start point*/
		if(strcmp(argv[temp], "-start") == 0){
			STARTING_POINT_CALC = atoi(argv[temp+1]);
			++temp;
		}
		/*change end point*/
		if(strcmp(argv[temp], "-end") == 0){
			ENDING_POINT_CALC = atoi(argv[temp+1]);
			++temp;
		}
	}
	
	/*start clock*/
	if(flags[1]==1){
		 begin = clock();
	}
	/*start multithreading*/
	#pragma omp parallel if(MULTITHREAD)
	
	/*start calculating*/
	if(flags[0]==1){	
		for(number = STARTING_POINT_CALC; number < ENDING_POINT_CALC; ++number){
			fastbruteforceInt(number);
		}
	} else {
		for(number = STARTING_POINT_CALC; number < ENDING_POINT_CALC; ++number){
			bruteforceInt(number);
		}
	}
	/*end clock and calculate time*/
	if(flags[1]==1){
		end = clock();
		time_spent = (double)(end - begin) / (CLOCKS_PER_SEC * NUM_OF_THREADS);
		printf("Time spent: %f seconds\n", time_spent);
	}
	return 0;
}

int bruteforceInt(long int checkNumber){
	long int i;
	int prime = 1;
	/*checks every single possible devision statement to see if it gives a remainder. If it doesn't, checkNumber is prime*/
	for(i = 1; i < checkNumber; ++i){
		if(checkNumber % i == 0 && i != 1){
			prime = 0;
		}
	}
	if(prime == 1 && checkNumber != 1){
		printf("%ld\n", checkNumber);
	}
	return 0;
}

int fastbruteforceInt(long int checkNumber){
	long int i,j;
	int prime = 1;
	/*checks devision statement to see if it gives a remainder. If it doesn't, checkNumber is prime and end condition is set to answer + 1.*/
	for(i = 1, j = checkNumber; i < j; ++i){
		if(checkNumber % i == 0 && i != 1){
			prime = 0;
			break;
		}
		else {
			/*Weird case, doesnt work with 2.*/
			if(checkNumber != 2){
				j = (checkNumber/i) + 1;
			}
		}
	}
	if(prime == 1 && checkNumber != 1){
		printf("%ld\n", checkNumber);
	}
	return 0;
}

int formulaInt(int checkNumber){
	return 0;
}
