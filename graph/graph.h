#ifndef GRAPH_H
#define GRAPH_H

#include "../collections/collections.h"
#include <stdio.h>

typedef struct vertex_t{
	
	void* data;
	list_t* adjacencies;

}vertex_t;

typedef struct edge_t{

	vertex_t* neighboor;
	void* weight;
}edge_t;

typedef struct graph_t{

	size_t type_size;
	size_t weight_type;
	list_t* vertex;

}graph_t;

graph_t* new_graph(size_t type_size, size_t weight_type);
vertex_t* new_vertex(size_t type_size, void* data);
edge_t* new_edge(vertex_t* neighboor,void* weight);
vertex_t* graph_add_vertex(graph_t* graph, void* value);
vertex_t* graph_get_vertex_by_position(graph_t* graph, int position);
vertex_t* graph_get_vertex_by_data(graph_t* graph, void* value, int (*compare)(void*, void*));
void graph_add_adjacency(vertex_t* vertex, vertex_t* neighboor,void* weight, int digraph);
void graph_add_adjacency_by_data(graph_t* graph, void* data,
 void* data2, void* weight, int digraph, int (*compare)(void*, void*));


#include "graph.c"

#endif