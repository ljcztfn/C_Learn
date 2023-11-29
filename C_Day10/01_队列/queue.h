// �ӿ�
#include <stdbool.h>
#define N 10

typedef struct{
	int elements[N];
	int front;
	int rear;
} Queue;

// �����յĶ���
Queue* Queue_create();
void Queue_destroy(Queue* q);

void enqueue(Queue* q, int val);
int dequeue(Queue* q);
int peek(Queue* q);
bool isEmpty(Queue* q);
bool isFull(Queue* q);