#include "Map.h"
#include <stdio.h>
#include <stdlib.h>

//Map Methods------------------------------------------------------------------
Map* createMap(unsigned int buckets) {
	Map* map = (Map*) malloc(sizeof(Map));
	map->table = (List**) calloc(buckets, sizeof(List*));
	map->buckets = buckets;
	map->size = 0;
	return map;
}

void destroyMap(Map* map) {
	if (map == NULL) return;
	int i;
	for (i = 0; i < map->buckets; i++) {
		if (map->table[i] != NULL) {
			destroyList(map->table[i]);
		}
	}
	free(map->table);
	free(map);
}

List* findList(Map* map, unsigned int acc_num) {
	if (map == NULL) return NULL;
	unsigned int index = hash(acc_num, map->buckets);
	if (map->table[index] == NULL) {
		map->table[index] = createList();
	}
	return map->table[index];
}

int withdrawMap(Map* map, unsigned int acc_num, int amount) {
	if (map == NULL) return;
	List* list = findList(map, acc_num);
	return withdrawList(list, acc_num, amount);
}

int depositMap(Map* map, unsigned int acc_num, int amount) {
	if (map == NULL) return;
	List* list = findList(map, acc_num);
	return depositList(list, acc_num, amount);
}

int feeMap(Map* map, unsigned int acc_num, int amount) {
	if (map == NULL) return;
	List* list = findList(map, acc_num);
	return feeList(list, acc_num, amount);
}

unsigned int hash(unsigned int num, unsigned int max) {
	return num % max;
}

void printMap(Map* map) {
	int i;
	for (i = 0; i < map->buckets; i++) {
		printf("Index: %d\n", i);
		if (map->table[i] != NULL) {
			printList(map->table[i]);
		}
	}
}
//End Map Methods--------------------------------------------------------------