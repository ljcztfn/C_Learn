#include <stdio.h>
#include "mystack.h"

int main(void) {
	// ø’’ª
	Node* top = NULL;
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);

	printf("%d\n", peek(top));
	while (!isEmpty(top)) {
		printf("%d ", pop(&top));
	}
	printf("\n");

	return 0;
}

