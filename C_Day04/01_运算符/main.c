#include <stdio.h>
#include <stdbool.h>

bool is_odd(int n);
int findSingleNumber(int arr[], int n);
bool isPowerOf2(unsigned int n);

int main(void) {
	/*float f;
	int i;

	f = i = 3.33f;*/

	//int i = 1;
	//printf("i = %d\n", i--); // 1
	//printf("i = %d\n", i);   // 0

	//printf("i = %d\n", --i); // -1
	//printf("i = %d\n", i);   // -1


	//int i, j, k;
	//i = 1;
	//j = 2;
	//k = ++i + j++;

	//printf("i = %d, j = %d, k = %d\n", i, j, k);


	//short s = 13;
	//printf("s >> 2 = %d", s >> 2);

	// printf("s << 2 = %d\n", s << 2);


	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	int singleNumber = findSingleNumber(arr, 9);

	printf("%d\n", singleNumber);

	return 0;
}

bool is_odd(int n) {
	return n & 0x1;
}

//判断一个整数是否为2的幂
//bool isPowerOf2(unsigned int n) {
//	unsigned int i = 1;
//	while (i < n) {
//		i <<= 1;
//	}
//	return i == n;
//}

//2的幂的二进制有什么特性：只用一个1
bool isPowerOf2(unsigned int n) {
	return (n & n - 1) == 0;
}

int findSingleNumber(int arr[], int n) {
	int singleNum = 0;
	for (int i = 0; i < n; i++) {
		singleNum ^= arr[i];
	}
	return singleNum;
}