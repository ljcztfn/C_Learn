#include <stdio.h>

int main()
{
	//printf("%4d\n", 123);	//默认右对齐
	//printf("%-4d\n", 123);	//添加“-”左对齐
	//printf("%4d\n", 1234);
	//printf("%4d\n", 12345);	//自动扩展

	//int i = 40;
	//float f = 125.55f;
	//printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
	//printf("|%f|%10f|%10.2f|%-10.2f|\n", f, f, f, f);

	int n = printf("Hello world.\n");


	return 0;
}