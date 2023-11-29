#include <stdio.h>

void foo();
void bar();

int main(void) {
	// printf("n = %d\n", n);
	foo();
	bar();

	return 0;
}

int n = 10;

void foo() {
	printf("n = %d\n", n);
}

void bar() {
	printf("n = %d\n", n);
}