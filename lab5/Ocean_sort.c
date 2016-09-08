#include <stdio.h>
#include <stdlib.h>
#define OCEAN_MAX 100



struct ocean_datum {

int x;
/* grid-reference east-west
*/
int y;
/* grid-reference north-south
*/
double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};

void print_ocean_datum(struct ocean_datum *o,int n) {
	if(n>0){
	printf("%d %d %.4f\n", (*o).x, (*o).y, (*o).conc);
	print_ocean_datum(o+1,n-1);
	}
}

int read_ocean_datum(struct ocean_datum *o) {
return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

void insertion_sort(struct ocean_datum a[],int n){
 	int i=0,j=0;
        struct ocean_datum key;
        for(i=0;i<n;i++)
	{printf("%d %d %f\n",a[i].x,a[i].y,a[i].conc);
	}
	printf("\n"); 
	for(i=1;i<n;i++){
	
	  key=a[i];   
	for(j=i-1;j>=0 && (a[j].conc > key.conc);j--){
	   a[j+1]=a[j];  	    	    
	}
	a[j+1]=key;		

	
	}	


}


int main(void) {

struct ocean_datum ocean_data[OCEAN_MAX];
int num_items;
int i;
num_items = 0;

while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
num_items++;
}

/* sort the data here */
insertion_sort(ocean_data,num_items); 

/* print out the array of structs */

print_ocean_datum(ocean_data,num_items);


return EXIT_SUCCESS;

}
