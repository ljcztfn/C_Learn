#include <stdio.h>

//#define SUIT int
//#define SPADE 0
//#define HEART 1
//#define CLUB  2
//#define DIAMOND 3

typedef enum suit {
	SPADE,
	HEART = 7,
	CLUB,
	DIAMOND = 16
} Suit;

int main(void) {
	Suit s1 = SPADE;
	Suit s2 = HEART;
	Suit s3 = CLUB;
	Suit s4 = DIAMOND;
	return 0;
}