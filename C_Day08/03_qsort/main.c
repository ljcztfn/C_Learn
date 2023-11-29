#include <stdio.h>
#include <string.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

typedef struct student_s {
	int number;
	char name[25];
	int chinese;
	int math;
	int english;
} Student;

int compare(const void* p1, const void* p2);

int main(void) {
	Student students[5] = { {1, "liuyifei", 100, 100, 100}, {2, "wangyuyan", 99, 100, 100}, 
		{3, "zhaolinger", 100, 99, 100}, {4, "xiaolongnv", 100, 100, 99}, {5, "baixiuzhu", 100, 100, 99}};
	qsort(students, SIZE(students), sizeof(Student), compare);

	return 0;
}

// 比较规则: 总分从高到底, 语文成绩(高-->低), 数学成绩(高-->低), 英语成绩(高-->低), 姓名(字典顺序从小到大进行比较)
int compare(const void* p1, const void* p2) {
	Student* s1 = (Student*)p1;
	Student* s2 = (Student*)p2;
	int total1 = s1->chinese + s1->english + s1->math;
	int total2 = s2->chinese + s2->english + s2->math;
	if (total1 != total2) {
		return total2 - total1;
	}
	if (s1->chinese != s2->chinese) {
		return s2->chinese - s1->chinese;
	}
	if (s1->math != s2->math) {
		return s2->math - s1->math;
	}
	if (s1->english != s2->english) {
		return s2->english - s1->english;
	}
	return strcmp(s1->name, s2->name);
}