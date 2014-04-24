#include <math.h>
#include <stdio.h>

#define UPPER_BOUND 100000000


size_t isPrime(size_t n) {
	
	size_t num = (size_t) (sqrt((double) n) + 1);
	int i;
	for (i = 2; i < num; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main(int argc, char** argv) {

	size_t i, count = 0;
	for (i = 2; i < UPPER_BOUND; i++) {
		if (isPrime(i)) count++;
	}

	printf("The number of primes less than %zu equals = %zu\n", i, count);

	return 0;
}