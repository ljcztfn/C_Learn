#include "rbtree.h"
#include <stdio.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

int main(void) {
	RBTree* tree = RBTree_create();
	char arr[] = { 'E', 'B', 'A', 'D', 'C'};
	for (int i = 0; i < SIZE(arr); i++) {
		RBTree_insert(tree, arr[i]);
	}

	RBTree_inOrder(tree);
	printf("\n");
	RBTree_levelOrder(tree);
	printf("\n");

	return 0;
}

