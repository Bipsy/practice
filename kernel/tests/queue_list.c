// @DISABLE_SWAPS
#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

// Create an entry for every possible task.  We recycle these entries
// as a task cannot appear in more than one queue at any time
#define MAX_TASKS 10
#define NO_TASK -1
#define TRUE 1
#define FALSE 0
Node tasks[MAX_TASKS];

Node* getNode(tid_t tid) {
	Node* node = &tasks[tid];
	node->tid = tid;
	node->next = NULL;
	return node;
}

void clearNode(Node* node)
{
	if (node != NULL) {
		node->tid = 0;
		node->next = NULL;
	}
	return;
}

QueueList* makeQueue(unsigned short priority) {
    QueueList* queue = (QueueList*) malloc(sizeof(QueueList));
	queue->curNode = NULL;
	queue->lastNode = NULL;
	queue->nextList = NULL;
	queue->priority = priority;
    return queue;
}


int removeNode(QueueList* list, tid_t tid)
{
	if (list == NULL) return FALSE;
	Node* current = list->curNode;
	Node* previous = NULL;

	while (current != NULL) {
		if (current->tid == tid) {
			if (previous == NULL) {
				list->curNode = current->next;
				if (current->next == NULL) list->lastNode = NULL;
				clearNode(current);
				return TRUE;
			} else {
				previous->next = current->next;
				if(current->next == NULL) list->lastNode = previous;
				clearNode(current);
				return TRUE;
			}
		} else {
			previous = current;
			current = current->next;
		}
	}

	return NO_TASK;

}

void enqueue(QueueList* list, tid_t tid)
{
	if (list == NULL) return;
	Node* node = getNode(tid);
	node->next = NULL;
	if (list->lastNode != NULL) {
		list->lastNode->next = node;
	} else {
		list->curNode = node;
	}
	list->lastNode = node;
    return;
}

int dequeue(QueueList* list)
{
	if (list == NULL) return NO_TASK;
	if (list->curNode == NULL) return NO_TASK;
	int tid = list->curNode->tid;
	list->curNode = list->curNode->next;
	if (list->curNode == NULL) list->lastNode = NULL;

    return tid;
}


void clearList(QueueList *list)
{
	return;
}

void clearListNode(QueueList *list)
{
	return;
}

// @ENABLE_SWAPS
