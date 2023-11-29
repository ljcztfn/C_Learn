#include <stdbool.h>

// 链表的接口
typedef struct node_s {
	int val;
	struct node_s* next;
} Node;		//结点

typedef struct linkedlist_s {
	Node* head;
	Node* tail;
	int size;
} LinkedList;		//链表指针（头尾指针）结点个数

// 构造方法: 创建一个空链表
LinkedList* create_list();

// 析构方法：释放堆堆存空间
void destroy_list(LinkedList* list);

void add_before_head(LinkedList* list, int val);
void add_behind_tail(LinkedList* list, int val);
void add_node(LinkedList* list, int index, int val);

// 删除第一个与val相等的结点, 如果没有这样的结点返回false
bool remove_node(LinkedList* list, int val);

// 找出第一个与val相等结点的索引，如果没有这样的结点, 返回-1
int indexOf(LinkedList* list, int val);