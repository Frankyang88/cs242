#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
 int num=atoi(argv[1]);
 int data;
 int i;
 for(i=0;i<num;i++){
 	data=rand() % 2000000; 
 	printf("%d \n",data);
}

return 0;
}
