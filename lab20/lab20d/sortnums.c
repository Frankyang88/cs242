#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main() {
int item;

flexarray f;

f = flexarray_new();


while (1 == scanf("%d", &item)) {
	flexarray_append(f, item);
}
flexarray_sort(f);
flexarray_print(f);
flexarray_free(f);
return EXIT_SUCCESS;
}
