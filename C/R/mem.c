#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1000000000

int main(int argc, char** argv) {

	int* array = (int*) malloc(sizeof(int) * BUF_SIZE);
	if (array == 0) {
		printf("Error");
	}

	int i;
	for (int i = 0; i < BUF_SIZE; i++) {
		*array++ = 1;
	}
		

	return 0;
}
