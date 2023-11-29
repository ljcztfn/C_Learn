#include <stdbool.h>

// ����Ľӿ�
typedef struct node_s {
	int val;
	struct node_s* next;
} Node;		//���

typedef struct linkedlist_s {
	Node* head;
	Node* tail;
	int size;
} LinkedList;		//����ָ�루ͷβָ�룩������

// ���췽��: ����һ��������
LinkedList* create_list();

// �����������ͷŶѶѴ�ռ�
void destroy_list(LinkedList* list);

void add_before_head(LinkedList* list, int val);
void add_behind_tail(LinkedList* list, int val);
void add_node(LinkedList* list, int index, int val);

// ɾ����һ����val��ȵĽ��, ���û�������Ľ�㷵��false
bool remove_node(LinkedList* list, int val);

// �ҳ���һ����val��Ƚ������������û�������Ľ��, ����-1
int indexOf(LinkedList* list, int val);