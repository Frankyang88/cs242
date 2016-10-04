#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

/*struct for vertex 
 * record its predecessor,distance to source, status and finish time
 * */
struct vertex{
  int predecessor;
  int distance;
  state_t state;
  int finish;	
};

/* graphrec
 * graph with number of nodes :size
 * @vertice array: record status of vertice
 * @edge array : record edge info
 * */
struct graphrec{
  int size;
  struct vertex *vertice_array;
  int **edge_array;
};


/* graph free:
 * free memory for graph g
 * */
void graph_free(graph g){
  int i;
  for(i=0;i<g->size;i++){
    free(g->edge_array[i]);
	
  }

  free(g->vertice_array);
  free(g->edge_array);
  free(g);
}


/* graph new:
 * create a new graph with number of vertices
 *
 * @param vertices : the number of vertices in graph
 * */
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
/* graph add edge:
 * @param g:graph g
 * @param u_index: vertex u
 * @param v_index: vertex v
 * @param direct flag: indicate whether it is directional(1) or undirectional(0)
 * add edge to a graph g,connect u and v
 *
 *
 * */
int graph_add_edge(graph g, int u_index,int v_index,int direct_flag){
  if(u_index<g->size && v_index<g->size && direct_flag == 1)
    g->edge_array[u_index][v_index]=1;
	
  if(u_index<g->size && v_index<g->size && direct_flag == 0){
    g->edge_array[u_index][v_index]=1;
    g->edge_array[v_index][u_index]=1;
  }

  return 0;
}
/* grapg print:
 * @param:g
 * @param:stream
 * 
 * output the adjacency list ot stream(stdout,stderr or file ,etc)
 * */
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
/* graph bfs:
 * @param g:graph
 * @param n: the source vertex 
 * apply bfs from source vertex to all the connected vertices
 * enqueue the adjacent vertice to source vertex 
 * dequeue the first item in the queue and visit its adjacent vertex, update their distance,precedessor
 * Then enqueue these these visited vertices and so on, until the queue is empty
 *
 * At the end,print the vertice info(vertice, distance ,predecessor) with bfs search
 * */
void graph_bfs(graph g,int n){
  queue q=queue_new(g->size);

  int i;
	
  for(i=0;i<g->size;i++){
    g->vertice_array[i].state=UNVISITED;
    g->vertice_array[i].distance=-1;
    g->vertice_array[i].predecessor=-1;
  }
  g->vertice_array[n].state=VISITED_SELF;
  g->vertice_array[n].distance=0;
  enqueue(q,n);


	
  while(queue_size(q)!=0){
    int u = dequeue(q);
		
    for(i=0;i<g->size;i++){
      if(g->edge_array[u][i]==1 && g->vertice_array[i].state == UNVISITED){
	g->vertice_array[i].state 	  = VISITED_SELF;
	g->vertice_array[i].distance    = g->vertice_array[u].distance+1; 
	g->vertice_array[i].predecessor = u;
			  	
	enqueue(q,i);
      }
    }	
    g->vertice_array[u].state= VISITED_DECENDANTS; 
  }

  printf("vertex distance pred\n");
  for(i=0;i<g->size;i++){
    printf("%4d %8d %4d\n",i,g->vertice_array[i].distance,g->vertice_array[i].predecessor);
  }


  queue_free(q);
}


