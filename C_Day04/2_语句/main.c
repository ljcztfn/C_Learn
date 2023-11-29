#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LINES 25

int main(void) {
	/*int line_num = 10;
	int page_num;

	if (line_num == MAX_LINES) {
		line_num = 0;
		page_num++;
	}*/

	//int n;
	//scanf("%d", &n);

	//if (n > 0)
	//	printf("n is positive.\n");
	//else if (n == 0)
	//	printf("n is zero.\n");
	//else
	//	printf("n is negative\n");


	//int grade;
	//scanf("%d", &grade);

	//switch (grade) {
	//	case 4: 
	//		printf("Excellent!\n");
	//	case 3:
	//		printf("Good.\n");
	//	case 2:
	//		printf("Average.\n");
	//	case 1:
	//		printf("Poor.\n");
	//	case 0:
	//		printf("Failing.\n");
	//	default:
	//		printf("Illegal grade.\n");
	//}

	/*int i, j, k;

	i = 1;
	j = 2;
	k = i > j ? i : j;
	k = i > j ? i++ : j++;
	k = (i >= 0 ? i : 0) + j;*/

	//int i = 10;

	//while (i > 0){
	//	printf("Counting down: %d\n", i--);
	//} 

	//for (int i = 10; i > 0; i--) {
	//	printf("Counting down: %d\n", i);
	//}

	//int n;
	//while (1) {
	//	printf("Enter a number (enter 0 to stop): ");
	//	scanf("%d", &n);

	//	if (n == 0) {
	//		break;
	//	}
	//	printf("%d squared is %d\n", n, n * n);
	//}

	//int sum = 0, count = 0, n;

	//while (count < 10) {
	//	scanf("%d", &n);
	//	if (n == 0) {
	//		continue;
	//	}
	//	sum += n;
	//	count++;

	//}
	//printf("sum = %d\n", sum);

	int sum, count, n;

	for (sum = 0, count = 0; count < 10; count++) {
		scanf("%d", &n);
		if (n == 0) {
			continue;
		}
		sum += n;

	}
	printf("sum = %d\n", sum);

	return 0;
}