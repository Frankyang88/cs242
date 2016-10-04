#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "mylib.h"

/*vertex status*/
struct vertex{
int predecessor;
int distance;
state_t state;
int finish;	
};
/*graph :
 *@param : size, number of vertex
  @param : vertice_array: array of vertex status
  @param: edge_array: array of edge
*/
struct graphrec{
int size;
struct vertex *vertice_array;
int **edge_array;
};


/* graph_free:
   free the memory for graph
*/
void graph_free(graph g){
	int i;
	for(i=0;i<g->size;i++){
		free(g->edge_array[i]);
	
	}
	free(g->vertice_array);
	free(g->edge_array);
	free(g);
}

/*graphnew: create a new graph with 
 @param: vertices, number of vertice in the graph
*/
graph graph_new(int vertices){
	int i,j;
	graph g=emalloc(sizeof(*g));
	g->size=vertices;
	g->vertice_array=emalloc(vertices*sizeof(struct vertex));
	g->edge_array   =emalloc(vertices*sizeof(int*));
	
	

	for(i=0;i<g->size;i++){
		g->edge_array[i]=emalloc(vertices*sizeof(int));
	}	
	
	for(i=0;i<g->size;i++){
		for(j=0;j<g->size;j++)
		g->edge_array[i][j] = 0;
	}
	return g;
}
/*graph add edge:add a edge(u,v) to graph,
 @param:g,graph
 @param:u_index, vertex u
 @param:v_index, vertex v
 @ direct flag: 1 means directional, 0 means undirectional
*/
int graph_add_edge(graph g, int u_index,int v_index,int direct_flag){
	if(u_index<g->size && v_index<g->size && direct_flag == 1)
	g->edge_array[u_index][v_index]=1;
	
	if(u_index<g->size && v_index<g->size && direct_flag == 0){
	g->edge_array[u_index][v_index]=1;
	g->edge_array[v_index][u_index]=1;
	}
	return 0;
}

/* graph print
   @ stream: the output, stdout,stderr or file
   print the graph g 's adajacent list to stdout or stderr or file

*/
void graph_print(graph g, FILE *stream){
	int i,j;
	int flag;
	fprintf(stream,"adjacency list:\n");
	for(i=0;i<g->size;i++){
		fprintf(stream,"%d |",i);
		flag=0;
		for(j=0;j<g->size;j++){
			if(g->edge_array[i][j]==1 && flag!=0){
			fprintf(stream,", %d",j);
			}
			if(g->edge_array[i][j]==1 && flag==0){
			fprintf(stream," %d",j);
			flag=1;
			}
		}
		fprintf(stream,"\n");
	}



}

/*@variable step: keep track of the first time and the finish time when the vertex is visited
*/
static int step;

/*visit:
 @param v: the vertex visited for the moment
 this method is recursive operation on the visited nodes 
 visit a vertex,mark the first time when the vertex is visited
 then visit its adjacent list,and so on
 after finishing the traversal to its adjacent list
 mark the finish time for the current vertex 
*/
void visit(graph g, int v){
	int i;
	
	
	g->vertice_array[v].state=VISITED_SELF;
	step++;
	g->vertice_array[v].distance = step;

	for(i=0;i<g->size;i++){
		if(g->edge_array[v][i]==1 && g->vertice_array[i].state == UNVISITED){
			g->vertice_array[i].predecessor = v;
			visit(g,i);
		}
	}
	step++;
	g->vertice_array[v].state = VISITED_DECENDANTS;
	g->vertice_array[v].finish = step;


}
/* dfs search on graph g
   initialise all the status of vertice
   then visited  the first vertex(index with 0)
   Stop until all the vertice are visited
   At last, print out vertex status to std out   
*/
void graph_dfs(graph g ){
	int i;
		
	step = 0;
	for(i=0;i<g->size;i++){
		g->vertice_array[i].state=UNVISITED;
		g->vertice_array[i].predecessor=-1;
	}
	for(i=0;i<g->size;i++){
		if(g->vertice_array[i].state==UNVISITED){
			visit(g,i);
		}
	}
	printf("vertex distance pred finish\n");
	for(i=0;i<g->size;i++){
		printf("%4d %8d %4d %4d\n",i,g->vertice_array[i].distance,g->vertice_array[i].predecessor,g->vertice_array[i].finish);
	}
	

}


