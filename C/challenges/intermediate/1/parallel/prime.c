#include "Buffer.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define UPPER_BOUND 1000000
#define NUM_THREADS 10
#define BUF_SIZE 1000


typedef struct Arg {
	size_t offset;
	size_t bound;
	size_t start;
	Buffer* buffer;
} Arg;

size_t isPrime(size_t n) {
	
	n = (size_t) (sqrt((double) n) + 1);
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void* primeCalculator(void* arg) {
	Arg* args = (Arg*) arg;
	size_t offset = args->offset;
	size_t bound = args->bound;
	size_t start = args->start;
	Buffer* buffer = args->buffer;
	int i;
	for (i = start; i < bound; i += offset) {
		int* res = (int*) malloc(sizeof(int));
		*res = isPrime(i);
		insertBuffer(buffer, (void*) res);
	}
}

int main(int argc, char** argv) {

	pthread_t threads[NUM_THREADS];
	Arg args[NUM_THREADS];
	Buffer* buffer = createBuffer(BUF_SIZE);

	size_t i, count = 0;
	for (i = 0; i < NUM_THREADS; i++) {
		args[i].buffer = buffer;
		args[i].bound = UPPER_BOUND;
		args[i].start = i+2;
		args[i].offset = NUM_THREADS;

		pthread_create(&(threads[i]), NULL, primeCalculator, (void*) &(args[i]));
	}

	for (i = 2; i < UPPER_BOUND; i++) {
		int* res = (int*) removeBuffer(buffer);
		if (*res == 1) {
			count++;
		}
	}

	printf("The number of primes less than %zu equals = %zu\n", i, count);

	return 0;
}
