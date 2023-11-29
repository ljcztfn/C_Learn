#include <stdio.h>


int binary_search(int arr[], int n, int key);
int binary_search1(int arr[], int n, int key);

int main(void) {
	int arr[] = { 0, 1, 2, 7, 7, 7, 7,7,7,7 , 7, 8, 9 };
	// int idx = binary_search(arr, 13, 7);
	// int idx = binary_search1(arr, 13, 7);
	// int idx = binary_search2(arr, 13, 6);
	// int idx = binary_search2(arr, 13, 7);
	int idx = binary_search2(arr, 13, -100);

	// int idx = binary_search(arr, 10, 9527);
	printf("%d\n", idx);

	return 0;
}

//int search(int arr[], int left, int right, int key) {
//	// �߽�����
//	if (left > right) return -1;
//	// int mid = (left + right) / 2;
//	int mid = left + (right - left >> 1);
//	if (key < arr[mid])
//		return search(arr, left, mid - 1, key);
//	else if(key > arr[mid])
//		return search(arr, mid + 1, right, key);
//	return mid;
//}

// �ݹ�
//int binary_search(int arr[], int n, int key) {
//	return search(arr, 0, n - 1, key);
//}

// ѭ��
int binary_search(int arr[], int n, int key) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		if (key < arr[mid]) {
			right = mid - 1;
		}
		else if (key > arr[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

// ���ҵ�һ����key��ȵ�Ԫ��
int binary_search1(int arr[], int n, int key) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		if (key < arr[mid]) {
			right = mid - 1;
		}
		else if(key > arr[mid]) {
			left = mid + 1;
		}
		else {
			if (mid == left || arr[mid - 1] < key) {
				return mid;
			}
			right = mid - 1;
		}
	}
	return -1;
}

// �������һ��С�ڵ���keyֵ��Ԫ��
int binary_search2(int arr[], int n, int key) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		if (arr[mid] > key) {
			right = mid - 1;
		}
		else {
			if (mid == right || arr[mid + 1] > key) {
				return mid;
			}
			left = mid + 1;
		}
	}
	return -1;
}