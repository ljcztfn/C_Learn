#include "hashmap.h"
#include <stdio.h>

int main(void) {
	HashMap* map = HashMap_create();
	HashMap_put(map, "liuyifei", 1);
	HashMap_put(map, "zhaolinger", 2);
	HashMap_put(map, "wuqing", 3);

	printf("%d\n", HashMap_get(map, "liuyifei"));
	HashMap_remove(map, "liuyifei");
	printf("%d\n", HashMap_get(map, "liuyifei"));
	// printf("%d\n", HashMap_get(map, "xiaolongnv"));

	return 0;
}