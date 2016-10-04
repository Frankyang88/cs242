#include <stdlib.h>
#include <stdio.h>


int main(void){
double s1,s2,s3;
int n;
double max_avg = 0;
int max_id = -1;
while(4==scanf("%d%lg%lg%lg",&n,&s1,&s2,&s3)){

	if(s1<=s2 && s1<=s3){
		if( (s2+s3)/2 > max_avg){
		max_avg = (s2+s3)/2;
		max_id = n;
		}
	}
	else if(s2<=s3 && s2<=s1){
		if( (s1+s3)/2 > max_avg){
		max_avg = (s1+s3)/2;
		max_id = n;
		}
	}
	else if(s3<=s2 && s3<=s1){
		if( (s2+s1)/2 > max_avg){
		max_avg = (s2+s1)/2;
		max_id = n;
		}
	}

}

if(max_id != 0){
  printf("%d\n",max_id);
}
else printf("exception\n");
return 0;
}
