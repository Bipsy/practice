#include "Buffer.h"
#include <semaphore.h>
#include <stdlib.h>

//Buffer Methods---------------------------------------------------------------
Buffer* createBuffer(int buf_size) {
	Buffer* buffer = (Buffer*) malloc(sizeof(Buffer));
	buffer->buf = calloc(buf_size, sizeof(void*));
	sem_init(&(buffer->empty), 0, buf_size);
	sem_init(&(buffer->full), 0, 0);
	sem_init(&(buffer->mutex), 0, 1);
	buffer->head = 0;
	buffer->tail = 0;
	buffer->max_size = buf_size;
}
void destroyBuffer(Buffer* buffer) {
	sem_destroy(&(buffer->empty));
	sem_destroy(&(buffer->full));
	sem_destroy(&(buffer->mutex));
	free(buffer->buf);
	free(buffer);
}
void* removeBuffer(Buffer* buffer) {
	sem_wait(&(buffer->full));
	sem_wait(&(buffer->mutex));
	void* arg = (void*)(((int**) buffer->buf)[buffer->tail]);
	if (buffer->tail == buffer->max_size-1) {
		buffer->tail = 0;
	} else {
		buffer->tail++;
	}
	sem_post(&(buffer->mutex));
	sem_post(&(buffer->empty));
	return arg;
}
void insertBuffer(Buffer* buffer, void* arg) {
	sem_wait(&(buffer->empty));
	sem_wait(&(buffer->mutex));
	((int**) buffer->buf)[buffer->head] = arg;
	if (buffer->head == buffer->max_size-1) {
		buffer->head = 0;
	} else {
		buffer->head++;
	}
	sem_post(&(buffer->mutex));
	sem_post(&(buffer->full));
}
//End Buffer Methods-----------------------------------------------------------