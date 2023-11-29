#include <stdio.h>

long long fib1(int n);
long long fib2(int n);
void hanoi(int n, char start, char middle, char target);
int joseph(int n);

int main(void) {
	
	// printf("%lld", fib2(60));
	// printf("%lld", fib1(60));
	// hanoi(3, 'A', 'B', 'C');

	printf("%d\n", joseph(7));
	printf("%d\n", joseph(8));
	return 0;
}

long long fib1(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib1(n - 1) + fib1(n - 2);
}

long long fib2(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	int a = 0, b = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = a + b; // 第i项的值
		// 为计算第i+1项做准备
		a = b;
		b = tmp;
	}
	return b;
}

void hanoi(int n, char start, char middle, char target) {
	// base case
	if (n == 1) {
		printf("%c --> %c\n", start, target);
		return;
	}
	// 递推公式
	hanoi(n - 1, start, target, middle);
	// 把最大的盘子从start移动到target上
	printf("%c --> %c\n", start, target);
	hanoi(n - 1, middle, start, target);
}

int joseph(int n) {
	if (n == 1 || n == 2) return 1;
	if (n & 0x1) {
		return 2 * joseph((n - 1) / 2) + 1;
	}
	return 2 * joseph(n / 2) - 1;
}