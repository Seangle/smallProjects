all: fibonacci prime

fibonacci:
	gcc -Wall -ansi -pedantic fibonacci.c -o fibonacci
prime:
	gcc -fopenmp -Wall -ansi -pedantic prime.c -o prime

clean:
	rm prime fibonacci
