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


/*scan the size of graph and create a new graph*/
if(1 == scanf("%d", &size) ){
	
	g=graph_new(size);
}
else {	
	return -1;
	
	}

/*scan the edge between two vertices, add the edge as undirectional edges to the graph*/
while(2 == scanf("%d %d",&u,&v)){
	
	graph_add_edge(g,u,v,0);
}
graph_print(g,stdout);
graph_bfs(g,1);

graph_free(g);

return 0;
}
