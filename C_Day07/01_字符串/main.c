#include <stdio.h>

int main(void) {
	// ��ά����
	/*char planets[][8] = { "Mecury", "Venus", "Earth", "Mars", "Jupitor", "Saturn",
						 "Uranus", "Neptune", "Pluto" };*/

	// �ַ�ָ������ (�Ƽ�ʹ��)
	char* planets[] = { "Mecury", "Venus", "Earth", "Mars", "Jupitor", "Saturn",
						 "Uranus", "Neptune", "Pluto" };

}



size_t my_strlen(const char* s) {
	char* p = s;
	while (*p) {
		p++;
	}
	return p - s;
}

char* my_strcat(char* s1, const char* s2) {
	char* p = s1;
	while (*p) {
		p++;
	}
	while (*p++ = *s2++)
		;
	return s1;
}