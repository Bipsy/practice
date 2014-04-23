#ifndef MAP_H_
#define MAP_H_

#include "List.h"

typedef struct Map {
	List** table;
	unsigned int buckets;
	unsigned int size;
} Map;

//Map Methods
Map* createMap(unsigned int buckets);
void destroyMap(Map* map);
List* findList(Map* map, unsigned int acc_num);
int withdrawMap(Map* map, unsigned int acc_num, int amount);
int depositMap(Map* map, unsigned int acc_num, int amount);
int feeMap(Map* map, unsigned int acc_num, int amount);
unsigned int hash(unsigned int num, unsigned int max);
void printMap(Map* map);
//-----------------------------------------------------------------------------
#endif
