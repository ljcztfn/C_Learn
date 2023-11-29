#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 10

//void bubble_sort(int arr[], int n);
//void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
//void shell_sort(int arr[], int n);
//void merge_sort(int arr[], int n);
//void quick_sort(int arr[], int n);
//void heap_sort(int arr[], int n);

int main(void) {
	int arr[N] = { 5, 8, 7, 1, 2, 0, 4, 9, 6, 3 };
	// bubble_sort(arr, N);
	// selection_sort(arr, N);
	 insertion_sort(arr, N);
	// shell_sort(arr, N);
	// merge_sort(arr, N);
	// quick_sort(arr, N);
	//heap_sort(arr, N);

	return 0;
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


///*****************************************************/
///*				ð������								 */
///*****************************************************/
//void bubble_sort(int arr[], int n) {
//	// i��ʾð�ݵĴ���
//	for (int i = 1; i < N; i++) {
//		bool isSorted = true;
//		for (int j = 0; j < N - i; j++) {
//			if (arr[j] > arr[j + 1]) { // ����д�� >=
//				swap(arr, j, j + 1);
//				isSorted = false;
//			}
//		}
//		// ð��֮���ж�isSorted
//		if (isSorted) return;
//		// print_arr(arr, n);
//	}
//}
//
///*****************************************************/
///*				ѡ������								 */
///*****************************************************/
//void selection_sort(int arr[], int n) {
//	for (int i = 1; i < n; i++) {
//		int minIndex = i - 1;
//		for (int j = i; j < N; j++) {
//			// ��������
//			if (arr[j] < arr[minIndex]) {
//				minIndex = j;
//			}
//		}
//		// ����i-1��minIndex����λ�õ�Ԫ��
//		swap(arr, i - 1, minIndex);
//		print_arr(arr, n);
//	}
//}
//
///*****************************************************/
///*				��������								 */
///*****************************************************/
void insertion_sort(int arr[], int n) {
	// i �����������ĵ�һ��Ԫ��
	for (int i = 1; i < n; i++) {
		int val = arr[i];
		int j = i - 1; 
		while (j >= 0 && arr[j] > val) {
			arr[j + 1] = arr[j];
			j--;
		}
		// j == -1 || arr[j] <= val
		arr[j + 1] = val;
		print_arr(arr, n);
	}
}

///*****************************************************/
///*				ϣ������								 */
///*****************************************************/
//
//void shell_sort(int arr[], int n) {
//	int gap = n / 2;
//	while (gap != 0) {
//		// ���ڲ�������
//		for (int i = gap; i < n; i++) {
//			int val = arr[i];
//			int j = i - gap;
//			while (j >= 0 && arr[j] > val) {
//				arr[j + gap] = arr[j];
//				j -= gap;
//			}
//			arr[j + gap] = val;
//		}
//		// ��С����
//		gap /= 2;
//		print_arr(arr, n);
//	}
//}
//
///*****************************************************/
///*				�鲢����								 */
///*****************************************************/
//
//void merge(int arr[], int left, int mid, int right) {
//	int len = right - left + 1;
//	int* temp = (int*)malloc(len * sizeof(int));
//	if (temp == NULL) {
//		printf("Error: malloc failed in merge.\n");
//		exit(1);
//	}
//	int i = left, j = mid + 1, k = 0;
//	while (i <= mid && j <= right) {
//		if (arr[i] <= arr[j]) { // ����д�� <
//			temp[k++] = arr[i++];
//		}
//		else {
//			temp[k++] = arr[j++];
//		}
//	}
//	while (i <= mid) {
//		temp[k++] = arr[i++];
//	}
//	while (j <= right) {
//		temp[k++] = arr[j++];
//	}
//	// ��������
//	for (int i = 0; i < len; i++) {
//		arr[left + i] = temp[i];
//	}
//	// �ͷ�
//	free(temp);
//}
//
//void merge_sort1(int arr[], int left, int right) {
//	// �߽�����
//	if (left >= right) return;
//	int mid = left + (right - left >> 1);
//	// �������������
//	merge_sort1(arr, left, mid);
//	// ���Ұ���������
//	merge_sort1(arr, mid + 1, right);
//	// �ϲ���������
//	merge(arr, left, mid, right);
//
//	print_arr(arr, N);
//}
//
//void merge_sort(int arr[], int n) {
//	merge_sort1(arr, 0, n - 1);
//}
//
///*****************************************************/
///*				��������								 */
///*****************************************************/
//
//int partition(int arr[], int left, int right) {
//	int pivot = arr[left];
//	int i = left, j = right;
//	while (i < j) {
//		while (i < j && arr[j] >= pivot) {
//			j--;
//		}
//		// i == j || arr[j] < pivot
//		arr[i] = arr[j];
//		while (i < j && arr[i] <= pivot) {
//			i++;
//		}
//		arr[j] = arr[i];
//	}
//	// i == j
//	arr[i] = pivot;
//
//	print_arr(arr, N);
//	return i;
//}
//
//void quick_sort1(int arr[], int left, int right) {
//	// �߽�����
//	if (left >= right) return;
//	// idx Ϊ��׼ֵ������
//	int idx = partition(arr, left, right);
//	quick_sort1(arr, left, idx - 1);
//	quick_sort1(arr, idx + 1, right);
//}
//
//void quick_sort(int arr[], int n) {
//	quick_sort1(arr, 0, n - 1);
//}
//
//
///*****************************************************/
///*				������								 */
///*****************************************************/
//
//void heapify(int arr[], int i, int len) {
//	// i ��ʾ����Υ���󶥶ѹ����������, len��ʾ�󶥶Ѱ���Ԫ�صĸ���
//	while (i < len) {
//		int leftChild = 2 * i + 1;
//		int rightChild = 2 * i + 2;
//		int maxIdx = i;
//		if (leftChild < len && arr[leftChild] > arr[maxIdx]) {
//			maxIdx = leftChild;
//		}
//		if (rightChild < len && arr[rightChild] > arr[maxIdx]) {
//			maxIdx = rightChild;
//		}
//		if (maxIdx == i) {
//			break;
//		}
//		swap(arr, i, maxIdx);
//		i = maxIdx;
//	}
//}
//
//// 2i + 1 <= n - 1 --> i <= (n-2)/2
//void build_heap(int arr[], int n) {
//	for (int i = (n - 2) / 2; i >= 0; i--) {
//		heapify(arr, i, n);
//	}
//}
//
//void heap_sort(int arr[], int n) {
//	// �����󶥶�
//	build_heap(arr, n);
//	printf("build_heap: ");
//	print_arr(arr, n);
//	// �������ĳ���
//	int len = n;
//	while (len > 1) {
//		swap(arr, 0, len - 1);
//		len--;
//		print_arr(arr, n);
//		// �����������µ����ɴ󶥶�
//		heapify(arr, 0, len);
//	}
//}