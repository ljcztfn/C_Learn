#include <stdio.h>
#include <stdlib.h>		//定义了三个动态内存分配的函数（在堆上分配分配内存空间）
//切记申请完空间要释放掉，否则造成内存泄露现象


char* my_strcat(const char* s1, const char* s2);

int main(void) {
	char* s1 = "Hell   o     ";
	char* s2 = "world.";
	char* s = my_strcat(s1, s2);
	puts(s1);
	puts(s2);
	puts(s);

	return 0;
}

char* my_strcat(const char* s1, const char* s2) {
	char* s = (char *)malloc(strlen(s1) + strlen(s2) + 1);	//预留一个空字符
	if (s == NULL) {		//内存分配不成功的情况
		// 做错误处理
		return NULL;
	}
	strcpy(s, s1);
	strcat(s, s2);
	return s;
}