#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue* Queue_create() {
	return (Queue*)calloc(1, sizeof(Queue));
}

void Queue_destroy(Queue* q);

void enqueue(Queue* q, E val) {
	if (isFull(q)) {
		printf("Error: queue is Full.\n");
		exit(1);
	}
	q->elements[q->rear] = val;
	// 更新rear的值
	q->rear = (q->rear + 1) % N;
}

E dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("Error: queue is Empty.\n");
		exit(1);
	}
	E removeValue = q->elements[q->front];
	q->front = (q->front + 1) % N;
	return removeValue;
}

E peek(Queue* q) {
	if (isEmpty(q)) {
		printf("Error: queue is Empty.\n");
		exit(1);
	}
	return q->elements[q->front];
}

bool isEmpty(Queue* q) {
	return q->front == q->rear;
}

bool isFull(Queue* q) {
	return q->front == (q->rear + 1) % N;
}