#include<stdio.h>	//����printf��Ҫʹ�ø�ͷ�ļ�
#include<stdlib.h>	//����system����ʹ�ø�ͷ�ļ�

//int main()
//{//�����忪ʼ
//	printf("Hello world!\n");
//	system("pause");	//��ɫ����̨ͣ��
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