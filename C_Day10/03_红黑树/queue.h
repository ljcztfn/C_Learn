// 接口
#include <stdbool.h>
#define N 10

typedef struct TreeNode_s TreeNode;
typedef TreeNode* E;

typedef struct {
	E elements[N];
	int front;
	int rear;
} Queue;

// 创建空的队列
Queue* Queue_create();
void Queue_destroy(Queue* q);

void enqueue(Queue* q, E val);
E dequeue(Queue* q);
E peek(Queue* q);
bool isEmpty(Queue* q);
bool isFull(Queue* q);
