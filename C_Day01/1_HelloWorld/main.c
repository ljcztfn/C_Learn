#include<stdio.h>	//函数printf需要使用该头文件
#include<stdlib.h>	//函数system语言使用该头文件

//int main()
//{//函数体开始
//	printf("Hello world!\n");
//	system("pause");	//黑色控制台停留
//	return 0;
//}

void foo();
int main(void)
{
	int i = 1, j = 2;
	foo();
	printf("i / j = %d\n", i / j);
	return 0;
}

void foo()
{
	int i, j;
	i = 10;
	j = 20;
	printf("Hello Kitty.\n");

}