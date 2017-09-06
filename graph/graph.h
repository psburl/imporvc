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
	double weight;
}edge_t;

typedef struct graph_t{

	size_t type_size;
	list_t* vertex;

}graph_t;

typedef struct graph_path_t{

	vertex_t* start;
	double distance;

}graph_path_t;

graph_t* new_graph(size_t type_size);
vertex_t* new_vertex(size_t type_size, void* data);
edge_t* new_edge(vertex_t* neighboor, double weight);
vertex_t* graph_add_vertex(graph_t* graph, void* value);
vertex_t* graph_get_vertex_by_position(graph_t* graph, int position);
vertex_t* graph_get_vertex_by_data(graph_t* graph, void* value, int (*compare)(void*, void*));
void graph_add_adjacency(vertex_t* vertex, vertex_t* neighboor,double weight, int digraph);
void graph_add_adjacency_by_data(graph_t* graph, void* data,
 void* data2, double weight, int digraph, int (*compare)(void*, void*));
graph_path_t* graph_min_distance(graph_t* graph, vertex_t* v, vertex_t* w, int (*compare)(void*, void*));

#include "graph.c"

#endif