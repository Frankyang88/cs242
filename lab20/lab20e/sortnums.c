#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {
int item;
int num;
flexarray my_flexarray;

my_flexarray = flexarray_new();
num=0;

while (1 == scanf("%d", &item)) {
	flexarray_append(my_flexarray, item);
	num++;
}
flexarray_sort(my_flexarray);
flexarray_print(my_flexarray);
flexarray_free(my_flexarray);
return EXIT_SUCCESS;
}
