#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	int letters[26];
	int numbers[10];
	memset(letters, 0, 26*sizeof(int));
	memset(numbers, 0, 10*sizeof(int));
	FILE* input = fopen(argv[1], "r");
	if (input == NULL) return 0;
	char* line;
	size_t n = 0;
	while (getline(&line, &n, input) != -1) {
		if (isdigit(line[0])) {
			printf("%c\n", line[0]);
			numbers[line[0]-48] += 1;
		} else {
			printf("%c\n", line[0]);
			printf("index: %d\n", line[0]-97);
			letters[line[0]-97] += 1;
		}
	}

	int sum = 0, i;
	for (i = 1; i < 10; i++) {
		sum += numbers[i] * i;
	}
	printf("Sum: %d\n", sum);
	for (i = 0; i < 26; i++) {
		if (letters[i]) {
			printf("%c: %d\n", i+97, letters[i]);
		}
	}
	

	return 0;
}
