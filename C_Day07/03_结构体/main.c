#include <stdio.h>
#include <stdbool.h>

typedef struct student_s {
	int number;
	char name[25];
	bool gender;   // true --> male, false --> female
	int chinese;
	int math;
	int english;
} Student;

void print_student(struct student_s* s);

int main(void) {

	/*struct student_s s1 = {1, "liuyifei", false, 100, 100, 100};
	struct student_s s2 = {2, "huasheng", true};*/

	Student s1 = { 1, "liuyifei", false, 100, 100, 100 };
	Student s2 = { 2, "huasheng", true };
	print_student(&s1);

	// printf("%u\n", sizeof(s1));

	return 0;
}

//void print_student(struct student_s s) {
//	printf("%d %s %d %d %d %d\n", s.number, s.name, s.gender, s.chinese, s.math, s.english);
//	// s.number = 100;
//}

//void print_student(struct student_s* s) {
//	printf("%d %s %d %d %d %d\n", (*s).number, (*s).name, (*s).gender, (*s).chinese, (*s).math, 
//		(*s).english);
//}

void print_student(Student* s) {
	printf("%d %s %d %d %d %d\n", s->number, s->name, s->gender, s->chinese, s->math,
		s->english);
}