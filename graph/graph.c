#include "../collections/collections.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

graph_t* new_graph(size_t type_size){

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

edge_t* new_edge(vertex_t* neighboor, double weight){

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

vertex_t* graph_get_vertex_by_data(graph_t* graph,
 void* value, int (*compare)(void*, void*)){

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
 vertex_t* neighboor, double weight, int digraph){

	list_append(vertex->adjacencies, new_edge(neighboor, weight));
	if(!digraph)
		list_append(neighboor->adjacencies, new_edge(vertex, weight));
}

void graph_add_adjacency_by_data(graph_t* graph, void* data,
 void* data2, double weight, int digraph, int (*compare)(void*, void*)){

	vertex_t* v1 = graph_get_vertex_by_data(graph, data, compare);
	assert(v1 != NULL);
	vertex_t* v2 = graph_get_vertex_by_data(graph, data2, compare);
	assert(v2 != NULL);
	graph_add_adjacency(v1, v2, weight,  digraph);
}


graph_path_t* graph_min_distance_recursion(graph_path_t* path, list_t* passed,
 vertex_t* c, vertex_t* w, int (*compare)(void*, void*)) {

	if (list_get_by_data(passed, c, compare) != NULL){
		path->distance = -1;
		return path;
	}

	list_append(passed, c);
	list_t* adjacencies = c->adjacencies;
	node_t* element = (node_t*)adjacencies->head;
	double min = -1;
	vertex_t* included = NULL;
	
	while(element != NULL){

		edge_t* edge = (edge_t*)element->data;
		if(compare(edge->neighboor, w)){
			if(min == -1 || min > edge->weight){
				min = edge->weight;
				included = edge->neighboor;
			}
		}
		else{

			graph_path_t* min_recursion = graph_min_distance_recursion(path,
				passed, (void*)edge->neighboor, w, compare);

			if(min_recursion->distance != -1 && (min == -1 || min > min_recursion->distance)){
				min = min_recursion->distance + edge->weight;
				included = edge->neighboor;
			}
		}

		element = element->next;	
	}

	path->distance = min;
	path->start = included;
	return path;
}


graph_path_t* graph_min_distance(graph_t* graph, vertex_t* v, vertex_t* w, int (*compare)(void*, void*)){

	graph_path_t* path = malloc(sizeof(graph_path_t));
	list_t* passed = new_list(sizeof(vertex_t));
	graph_min_distance_recursion(path, passed, v, w, compare);
	return path;
}