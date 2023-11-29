#include "mystack.h"
#include <stdlib.h>
#include <stdio.h>

void push(Node** ptr_top, int val) {
	// 创建新结点
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in push.\n");
		exit(1);
	}
	// 初始化结点
	newNode->val = val;
	// 头插法
	newNode->next = *ptr_top;
	*ptr_top = newNode;
}

int pop(Node** ptr_top) {
	if (isEmpty(*ptr_top)) {
		printf("Error: stack is Empty.\n");
		exit(1);
	}
	// 保存原来头结点的值
	Node* old_top = *ptr_top;
	int result = old_top->val;
	// 更新头结点
	*ptr_top = (*ptr_top)->next;
	free(old_top);
	return result;
}

bool isEmpty(Node* top) {
	return top == NULL;
}

// 查看栈顶元素的值
int peek(Node* top) {
	if (isEmpty(top)) {
		printf("Error: stack is Empty.\n");
		exit(1);
	}
	return top->val;
}