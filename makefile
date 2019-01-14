all: fibonacci prime permute

fibonacci:
	gcc -Wall -ansi -pedantic fibonacci.c -o fibonacci
prime:
	gcc -fopenmp -Wall -ansi -pedantic prime.c -o prime
permute:
	gcc -Wall -ansi -pedantic permute.c -o permute

clean:
	rm prime fibonacci permute
