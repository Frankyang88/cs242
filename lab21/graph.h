#include <stdio.h>
#include <stdlib.h>
#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct graphrec *graph;
typedef enum { UNVISITED, VISITED_SELF,VISITED_DECENDANTS} state_t;

extern void graph_free(graph g);
extern graph graph_new(int vertices);

extern void graph_print(graph g, FILE *stream);

extern int graph_add_edge(graph g, int u_index,int v_index,int direct_flag);

extern void graph_bfs(graph g,int n);

#endif
