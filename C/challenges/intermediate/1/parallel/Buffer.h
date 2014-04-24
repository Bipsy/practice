#ifndef BUFFER_H_
#define BUFFER_H_

#include <pthread.h>
#include <semaphore.h>

typedef struct Buffer {
	void* buf;
	sem_t empty;
	sem_t full;
	sem_t mutex;
	int head;
	int tail;
	int max_size;
} Buffer;

//Buffer Methods---------------------------------------------------------------
Buffer* createBuffer();
void destroyBuffer(Buffer* buffer);
void* removeBuffer(Buffer* buffer);
void insertBuffer(Buffer* buffer, void* arg);
//End Buffer Methods-----------------------------------------------------------

#endif