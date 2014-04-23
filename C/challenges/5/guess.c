#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv) {
	srand(time(NULL));
	int num = (rand() % 100) + 1;
	int guesses = 0;
	int guess;
	do {
		printf("Enter a guess between 0 and 101\n");
		scanf("%d", &guess);
		if (guess > num) {
			printf("Your guess was too high...\n");
		} else if (guess < num) {
			printf("Your guess was too low...\n");
		}
		printf("You have guessed %d times.\n\n", ++guesses);
	} while (guess != num);
	printf("You win!\n");
	return 0;
}
