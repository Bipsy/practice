#include "List.h"
#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 10

void parse(char* line, ssize_t len, Map* map) {
	char* command = strtok(line, " ");
	if (command == NULL) return;
	char* account = strtok(NULL, " ");
	unsigned int acc_num;
	if (account != NULL) {
		acc_num = atoi(account);
	}
	char* s_amount = strtok(NULL, " \n");
	unsigned int amount;
	if (s_amount != NULL) {
		amount = atoi(s_amount);
	}
	if (strncmp(command, "wd", 2) == 0) {
		withdrawMap(map, acc_num, amount);
	} else if (strncmp(command, "dep", 3) == 0) {
		depositMap(map, acc_num, amount);
	} else if (strncmp(command, "fee", 3) == 0) {
		feeMap(map, acc_num, amount);
	} else if (strncmp(command, "print", 5) == 0) {
		printMap(map);
	}
}

int main(int argc, char** argv) {
	FILE* file = fopen("input.txt", "r");
	
	Map* map = createMap(MAP_SIZE);
	char* line = NULL;
	size_t n = 0;
	ssize_t len;
	while ((len = getline(&line, &n, file)) > 1) {
		parse(line, len, map);
	}
	fclose(file);
	destroyMap(map);
	free(line);
	return 0;
}