// �����ʵ��
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

// ����������
LinkedList* create_list() {
	return (LinkedList*)calloc(1, sizeof(LinkedList));
}

// ͷ�巨
void add_before_head(LinkedList* list, int val) {
	// �����½��
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	// ��ʼ�����
	newNode->val = val;
	newNode->next = list->head;
	list->head = newNode;
	// �ж������Ƿ�Ϊ��
	if (list->tail == NULL) {
		list->tail = newNode;
	}
	// ����size
	list->size++;
}

// β�巨
void add_behind_tail(LinkedList* list, int val) {
	// �����½��
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	// ��ʼ�����
	newNode->val = val;
	newNode->next = NULL;
	// �ж������Ƿ�Ϊ��
	if (list->size == 0) {
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		// �����½��
		list->tail->next = newNode;
		// ����list->tail
		list->tail = newNode;
	}
	list->size++;
}

void add_node(LinkedList* list, int index, int val) {
	if (index < 0 || index > list->size) {
		printf("Error: Illegal index.\n");
		exit(1);
	}
	// �����½��
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	newNode->val = val;

	if (index == 0) {
		// ͷ�巨���߼�
		newNode->next = list->head;
		list->head = newNode;
	}
	else {
		// �ҵ�����Ϊ indx-1 �Ľ�㣬pָ��ָ��Ҫ���������index��ǰһ�����
		Node* p = list->head;
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		//������������ֵindex���ڽ�����list->size����pָ��ָ�����һ�����
		newNode->next = p->next;
		p->next = newNode;	
	}
	// ����β���
	if (index == list->size) {
		list->tail = newNode;
	}
	list->size++;
}

// ɾ����һ����val��ȵĽ��, ���û�������Ľ�㷵��false��currָ��ɾ����ǰ���
bool remove_node(LinkedList* list, int val) {
	Node* prev = NULL;
	Node* curr = list->head;
	// Ѱ��ǰ�����
	while (curr != NULL && curr->val != val) { // ��·ԭ��
		prev = curr;
		curr = curr->next;
	}
	// û��������Ԫ��
	if (curr == NULL) return false;
	// ɾ����һ��Ԫ�أ������ָ������һ��ֻ��һ����㣬���ǲ�ֹһ�����
	if (prev == NULL) {
		if (list->size == 1) {
			list->head = list->tail = NULL;
		}
		else {
			list->head = curr->next;
		}
		free(curr);
	}
	//ɾ���ǵ�һ��Ԫ�أ��������currָ�����һ�����
	else {
		prev->next = curr->next;
		if (prev->next == NULL) {
			list->tail = prev;
		}
		free(curr);
	}
	list->size--;
	return true;
}

// �ҳ���һ����val��Ƚ������������û�������Ľ��, ����-1
int indexOf(LinkedList* list, int val) {
	Node* curr = list->head;
	for (int i = 0; i < list->size; i++, curr = curr->next) {
		if (curr->val == val) {
			return i;
		}
	}
	// û���ҵ�
	return -1;
}

void destroy_list(LinkedList* list) {
	// �ͷŽ��ռ�
	Node* curr = list->head;
	while (curr != NULL) {
		// ����curr��̽��
		Node* next = curr->next;
		free(curr);
		curr = next;
	}
	// �ͷ�LinkedList�ṹ��
	free(list);
}