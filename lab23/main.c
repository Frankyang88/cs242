#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "mylib.h"

int main(){
graph g;
int size;
int v;
int u;
/*create a graph g with size(from input) */
if(1 == scanf("%d", &size) ){
	
	g=graph_new(size);
}
else {	
	return -1;
	
	}
/*scan input and add a directional edge to graph g*/
while(2 == scanf("%d %d",&u,&v)){
	
	graph_add_edge(g,u,v,1);
}
graph_print(g,stdout);
graph_dfs(g);

graph_free(g);

return 0;
}
