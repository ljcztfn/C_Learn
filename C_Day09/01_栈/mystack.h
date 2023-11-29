#include <stdbool.h>
// 栈的接口

typedef struct node_s {
	int val;
	struct node_s* next;
} Node;

void push(Node** top, int val);
int pop(Node** top);
bool isEmpty(Node* top);
// 查看栈顶元素的值
int peek(Node* top);