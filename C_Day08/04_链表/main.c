#include "linkedlist.h"

// ²âÊÔ
int main(void) {
	LinkedList* list = create_list();
	//add_before_head(list, 1);
	//add_before_head(list, 2);
	//add_before_head(list, 3);
	//add_before_head(list, 4);

	//add_behind_tail(list, 1);
	//add_behind_tail(list, 2);
	//add_behind_tail(list, 3);
	//add_behind_tail(list, 4);

	// 1-->2-->3-->4
	// remove_node(list, 1);
	// remove_node(list, 4);
	// remove_node(list, 2);
	// remove_node(list, 5);

	add_node(list, 0, 1);
	add_node(list, 0, 2);
	add_node(list, 1, 3);
	add_node(list, 3, 4);
	add_node(list, 4, 5);
	// 2-->3-->1-->4

	 printf("%d\n", indexOf(list, 3));
	//printf("%d\n", indexOf(list, 5));

	return 0;
}