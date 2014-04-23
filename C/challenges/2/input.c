#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int invalidUserName(char* line, ssize_t line_len, char* username) {
	//Trailing Whitespace is still included...
	if (isspace(line[0])) return 1;
	memcpy(username, line, line_len-1);
	username[line_len-1] = '\0';
	return 0;
}

unsigned int invalidNum(char* line, ssize_t line_len, int* num) {
	char* new_line = (char*) malloc(line_len+1);
	int j = 0;
	int i;
	for (i = 0; i < line_len; i++) {
		if (isdigit(line[i])) {
			new_line[j] = line[i];
			j++;
		} else if (isspace(line[i])) {
			continue;
		} else {
			free(new_line);
			return 1;
		}
	}
	new_line[j] = '\0';
	*num = atoi(new_line);
	free(new_line);
	if (*num > 0) return 0;
	return 1;
}

int main(int argc, char** argv) {
	const char* exit = "exit";
	char* lineptr = NULL;
	size_t n = 0;
	char* username;
	int age = 0;
	int user_id = 0;

	do {
		printf("What is your username?\n");
		ssize_t len = getline(&lineptr, &n, stdin);
		if (strncmp(lineptr, exit, len-1) == 0) return 0;
		if (len < 1) continue;
		username = (char*) calloc(len, sizeof(char));
		if (invalidUserName(lineptr, len, username)) continue;
		break;		
	} while (1);

	do {
		printf("What is your age?\n");
		ssize_t len = getline(&lineptr, &n, stdin);
		if (strncmp(lineptr, exit, len-1) == 0) return 0;
		if (len < 1) continue;
		if (invalidNum(lineptr, len, &age)) continue;
		//printf("%d\n", age);
		break;
	} while(1);

	do {
		printf("What is your userid?\n");
		ssize_t len = getline(&lineptr, &n, stdin);
		if (strncmp(lineptr, exit, len-1) == 0) return 0;
		if (len < 1) continue;
		if (invalidNum(lineptr, len, &user_id)) continue;
		if (user_id > 999999) continue;
		break;
	} while(1);

	printf("You are %s, aged %d next year you will be %d,"
			" with user id %d, the next user is %d.\n", username, age, age+1
													 , user_id, user_id+1);
	free(username);
	free(lineptr);

	return 0;
}

