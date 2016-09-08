#include <stdio.h>
#include <stdlib.h>

int factorial(int num){

	if(num==1)
	return 1;
	else if(num > 1)
	return factorial(num-1)*num;
	else return -1;

}

int main(){
	int num;
	while(1== scanf("%d",&num)){
	printf("%d\n",factorial(num));
}

return 0;
}

