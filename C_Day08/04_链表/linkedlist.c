// 链表的实现
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

// 创建空链表
LinkedList* create_list() {
	return (LinkedList*)calloc(1, sizeof(LinkedList));
}

// 头插法
void add_before_head(LinkedList* list, int val) {
	// 创建新结点
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	// 初始化结点
	newNode->val = val;
	newNode->next = list->head;
	list->head = newNode;
	// 判断链表是否为空
	if (list->tail == NULL) {
		list->tail = newNode;
	}
	// 更新size
	list->size++;
}

// 尾插法
void add_behind_tail(LinkedList* list, int val) {
	// 创建新结点
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	// 初始化结点
	newNode->val = val;
	newNode->next = NULL;
	// 判断链表是否为空
	if (list->size == 0) {
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		// 链接新结点
		list->tail->next = newNode;
		// 更新list->tail
		list->tail = newNode;
	}
	list->size++;
}

void add_node(LinkedList* list, int index, int val) {
	if (index < 0 || index > list->size) {
		printf("Error: Illegal index.\n");
		exit(1);
	}
	// 创建新结点
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_before_head.\n");
		exit(1);
	}
	newNode->val = val;

	if (index == 0) {
		// 头插法的逻辑
		newNode->next = list->head;
		list->head = newNode;
	}
	else {
		// 找到索引为 indx-1 的结点，p指针指向要插入链表的index的前一个结点
		Node* p = list->head;
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		//当想插入的索引值index等于结点个数list->size，即p指针指向最后一个结点
		newNode->next = p->next;
		p->next = newNode;	
	}
	// 更新尾结点
	if (index == list->size) {
		list->tail = newNode;
	}
	list->size++;
}

// 删除第一个与val相等的结点, 如果没有这样的结点返回false，curr指向删除当前结点
bool remove_node(LinkedList* list, int val) {
	Node* prev = NULL;
	Node* curr = list->head;
	// 寻找前驱结点
	while (curr != NULL && curr->val != val) { // 短路原则
		prev = curr;
		curr = curr->next;
	}
	// 没有这样的元素
	if (curr == NULL) return false;
	// 删除第一个元素，有两种个情况：一是只有一个结点，二是不止一个结点
	if (prev == NULL) {
		if (list->size == 1) {
			list->head = list->tail = NULL;
		}
		else {
			list->head = curr->next;
		}
		free(curr);
	}
	//删除非第一个元素，特殊情况curr指向最后一个结点
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

// 找出第一个与val相等结点的索引，如果没有这样的结点, 返回-1
int indexOf(LinkedList* list, int val) {
	Node* curr = list->head;
	for (int i = 0; i < list->size; i++, curr = curr->next) {
		if (curr->val == val) {
			return i;
		}
	}
	// 没有找到
	return -1;
}

void destroy_list(LinkedList* list) {
	// 释放结点空间
	Node* curr = list->head;
	while (curr != NULL) {
		// 保存curr后继结点
		Node* next = curr->next;
		free(curr);
		curr = next;
	}
	// 释放LinkedList结构体
	free(list);
}