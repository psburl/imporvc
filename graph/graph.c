#include "../collections/collections.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

graph_t* new_graph(size_t type_size, size_t weight_type){

	graph_t* graph = malloc(sizeof(graph_t));
	graph->type_size = type_size;
	graph->vertex = new_list(sizeof(vertex_t));

	return graph;
}

vertex_t* new_vertex(size_t type_size, void* data){

	vertex_t* vertex = malloc(sizeof(vertex_t));
	vertex->data = malloc(sizeof(type_size));
	vertex->adjacencies = new_list(sizeof(edge_t));
	memcpy(vertex->data, data, type_size);
	return vertex;
}

edge_t* new_edge(vertex_t* neighboor,void* weight){

	edge_t* edge = malloc(sizeof(edge_t));
	edge->weight = weight;
	edge->neighboor = neighboor;
	return edge;
}

vertex_t* graph_add_vertex(graph_t* graph, void* value){

	vertex_t* vertex = new_vertex(graph->type_size, value);
	list_append(graph->vertex, vertex);
	return vertex;
}

vertex_t* graph_get_vertex_by_position(graph_t* graph, int position){

	node_t* node = list_get_element(graph->vertex, position);
	assert(node != NULL);
	return (vertex_t*)node->data;
}

vertex_t* graph_get_vertex_by_data(graph_t* graph, void* value, int (*compare)(void*, void*)){

	list_t* vertex = graph->vertex;
	node_t* element = vertex->head;

	while(element != NULL){
		if(compare(((vertex_t*)element->data)->data, value))
			return element->data;
		element = element->next;
	}
	return NULL;
}

void graph_add_adjacency(vertex_t* vertex,
 vertex_t* neighboor, void* weight, int digraph){

	list_append(vertex->adjacencies, new_edge(neighboor, weight));
	if(!digraph)
		list_append(neighboor->adjacencies, new_edge(vertex, weight));
}

void graph_add_adjacency_by_data(graph_t* graph, void* data,
 void* data2, void* weight, int digraph, int (*compare)(void*, void*)){

	vertex_t* v1 = graph_get_vertex_by_data(graph, data, compare);
	assert(v1 != NULL);
	vertex_t* v2 = graph_get_vertex_by_data(graph, data2, compare);
	assert(v2 != NULL);
	graph_add_adjacency(v1, v2, weight,  digraph);
}


