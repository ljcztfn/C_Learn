#include <stdio.h>

int find_largest(int arr[], int n);

int main(void) {
	//int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//*arr = 100;
	//*(arr + 7) = 700;

	// arr++; 数组作为指针时是一个指针常量

	//int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int sum = 0;
	//
	//for (int* p = arr; p < arr + 10; p++) {
	//	sum += *p;
	//}
	//printf("sum = %d\n", sum);


	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int max = find_largest(arr, 10);

	printf("max = %d\n", max);

	return 0;
}

int find_largest(int* arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	
	//int max = *arr; // p[0] 等价于 *(p + 0)
	//for (int i = 0; i < n; i++) {
	//	if (*(arr + i) > max) {
	//		max = *(arr + i);
	//	}
	//}

	return max;
}