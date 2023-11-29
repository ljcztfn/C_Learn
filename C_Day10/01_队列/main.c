#include "queue.h"
#include <stdio.h>

int main(void) {
	Queue* q = Queue_create();
	for (int i = 0; i < N - 1; i++) {
		enqueue(q, i);
	}

	for (int i = 0; i < N - 1; i++) {
		printf("%d ", dequeue(q));
	}

	return 0;
}