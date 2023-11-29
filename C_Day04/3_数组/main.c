#include <stdio.h>
#include <stdlib.h>

//#define N 10
//#define M 20
//#define X 30

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

int main(void) {
	// int arr[10] = { 0 };

	//int arr[10]; // 类型为int[10], 变量名为arr
	//int brr[20];
	//int crr[30];

	//// sizeof(arr);
	//for (int i = 0; i < SIZE(arr); i++) {
	//	arr[i] = 0;
	//}

	// int matrix[3][4] = { {1, 2, 3, 4}, {2, 2, 3, 4} };

	// const int digits[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// digits[0] = 10;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		printf("%d\n", rand());
	}

	return 0;
}