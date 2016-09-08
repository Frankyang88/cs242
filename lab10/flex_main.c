#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
#include "mylib.h"

int main(void) {
int item;
int num;
num=0;
flexarray my_flexarray = flexarray_new();
while (1 == scanf("%d", &item)&& num<10) {
flexarray_append(my_flexarray, item);
num++;
}
flexarray_print(my_flexarray);
flexarray_sort(my_flexarray);
flexarray_print(my_flexarray);
flexarray_free(my_flexarray);
return EXIT_SUCCESS;
}
