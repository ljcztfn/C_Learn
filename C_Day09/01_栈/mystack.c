#include "mystack.h"
#include <stdlib.h>
#include <stdio.h>

void push(Node** ptr_top, int val) {
	// �����½��
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in push.\n");
		exit(1);
	}
	// ��ʼ�����
	newNode->val = val;
	// ͷ�巨
	newNode->next = *ptr_top;
	*ptr_top = newNode;
}

int pop(Node** ptr_top) {
	if (isEmpty(*ptr_top)) {
		printf("Error: stack is Empty.\n");
		exit(1);
	}
	// ����ԭ��ͷ����ֵ
	Node* old_top = *ptr_top;
	int result = old_top->val;
	// ����ͷ���
	*ptr_top = (*ptr_top)->next;
	free(old_top);
	return result;
}

bool isEmpty(Node* top) {
	return top == NULL;
}

// �鿴ջ��Ԫ�ص�ֵ
int peek(Node* top) {
	if (isEmpty(top)) {
		printf("Error: stack is Empty.\n");
		exit(1);
	}
	return top->val;
}