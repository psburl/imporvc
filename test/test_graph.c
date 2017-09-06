#include "../graph/graph.h"
#include "../collections/collections.h"
#include <stdio.h>

int compare(void* el, void* el1){

	return *(int*)el == *(int*)el1;
}

void print_edge(void* edge){
	printf("data: %d-%lf", *(int*)((edge_t*)edge)->neighboor->data, ((edge_t*)edge)->weight);
}

void print_vertex(void* v){
	printf("%d-", *(int*)((vertex_t*)v)->data);
}

int main(){

	graph_t* graph = new_graph(sizeof(int));
	int value = 1;
	graph_add_vertex(graph, &value);

	int val = 2;
	vertex_t* neighboor = graph_add_vertex(graph, &val);

	int find = 1;
	vertex_t* vertex = graph_get_vertex_by_data(graph, &find, compare);
	
	find = 3;
	vertex_t* vertex2 = graph_add_vertex(graph, &find);

	graph_add_adjacency(vertex, neighboor, 1.0, 0);
	graph_add_adjacency(vertex, vertex2, 3.1, 0);
	graph_add_adjacency(neighboor, vertex2, 2.0, 0);
	
	graph_path_t* path = graph_min_distance(graph, vertex, vertex2, compare);

	printf("%lf\n", path->distance);
	printf("%d\n", *(int*)((vertex_t*)path->start)->data);
    return 0;
}