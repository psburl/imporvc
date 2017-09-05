#include "../graph/graph.h"
#include "../collections/collections.h"
#include <stdio.h>

int compare(void* el, void* el1){

	return *(int*)el == *(int*)el1;
}

void print_edge(void* edge){
	printf("data: %d-%d", *(int*)((edge_t*)edge)->neighboor->data, *(int*)((edge_t*)edge)->weight);
}

int main(){

	graph_t* graph = new_graph(sizeof(int), sizeof(int));
	int value = 1;
	graph_add_vertex(graph, &value);

	int val = 2;
	vertex_t* neighboor = graph_add_vertex(graph, &val);

	int find = 1;
	vertex_t* vertex = graph_get_vertex_by_data(graph, &find, compare);
	
	size_t weight = 1;
	graph_add_adjacency(neighboor, vertex, &weight, 0);

	list_print(neighboor->adjacencies, print_edge);
	printf("\n");
    return 0;
}