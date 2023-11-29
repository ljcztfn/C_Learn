#include <stdio.h>
#include <errno.h>
#include <math.h>

int main(void) {
	// printf("%d\n", errno);
	// printf("%s\n", strerror(errno));
	perror("Error");
	log(0.0);
	// printf("%d\n", errno);
	// printf("%s\n", strerror(errno));
	perror("Error");

	return 0;
}