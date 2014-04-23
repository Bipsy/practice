#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define UPPER_BOUND 1000000

void* isPrime(void* arg) {
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main(int argc, char** argv) {

	pthread_t threads[2];
	int args[2];

	int i, count = 0;
	for (i = 2; i < UPPER_BOUND; i++) {
		

		if (isPrime(i)) {
			count++;
		}
	}
	printf("The number of primes less than %d equals = %d\n", i, count);

	return 0;
}