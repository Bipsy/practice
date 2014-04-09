#include "queue_list.h"
#include <stdio.h>

void test1() {

	QueueList* list = makeQueue(0);
	for (int i = 0; i < 10; i++) {
		enqueue(list, i);
		printf("Generating node with tid %d\n", list->lastNode->tid);
	}

	int sum = 0;
	for (Node* node = list->curNode; node != NULL; node = node->next) {
		sum += node->tid;
		printf("%d\n", node->tid);
	}

	if (sum == 45) {
		printf("Test 1 Passed\n");
	} else {
		printf("Test 1 Failed with sum value %d\n", sum);
	}
	return;

}


int main(int argc, char** argv) {
	test1();
	return 0;

}
