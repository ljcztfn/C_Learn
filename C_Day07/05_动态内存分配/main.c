#include <stdio.h>
#include <stdlib.h>		//������������̬�ڴ����ĺ������ڶ��Ϸ�������ڴ�ռ䣩
//�м�������ռ�Ҫ�ͷŵ�����������ڴ�й¶����


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
	char* s = (char *)malloc(strlen(s1) + strlen(s2) + 1);	//Ԥ��һ�����ַ�
	if (s == NULL) {		//�ڴ���䲻�ɹ������
		// ��������
		return NULL;
	}
	strcpy(s, s1);
	strcat(s, s2);
	return s;
}