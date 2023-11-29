#include <stdio.h>
#include <stdlib.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

void swap(int a, int b);
int sum_array(int arr[][4], int n);
void foo();

int main(void) {
	//int matrix[3][4] = { {1, 2, 3, 4}, {2, 2, 3, 4}, {3, 2, 3, 4} };

	//printf("sum = %d\n", sum_array(matrix, 3));

	//return 0;

	foo();
	printf("Exit from main.\n");
	return 0;
}

void foo() {
	printf("Exit from foo.\n");
	exit(EXIT_FAILURE);
}

int sum_array(int matrix[][4], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

