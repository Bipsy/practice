#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	char* line = NULL;
	size_t n;
	FILE* input = fopen("bhaarat.txt", "r+");
	FILE* output = fopen("out.txt", "w");
	int count = 1;
	while (getline(&line, &n, input) > 0) {
		strtok(line, " \r\n\f\t\v\b");
		char* word = strtok(NULL, " \r\n\f\t\v\b");
		if (word[0] == 'H' || word[0] == 'S') {
			fprintf(output, "%d. %s\n", count, word);
			count++;
		}
	}
	fprintf(input, "23. English\n");
	fclose(input);
	fclose(output);
	free(line);
	return 0;
}
