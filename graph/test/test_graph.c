#include "../../collections/collections.h"
#include "../graph.h"
#include <stdio.h>

int compare(void *el, void *el1) { return *(int *)el == *(int *)el1; }

void print_edge(void *edge) {
  printf("data: %d-%lf", *(int *)((edge_t *)edge)->neighboor->data,
         ((edge_t *)edge)->weight);
}

void print_vertex(void *v) { printf("%d", *(int *)((vertex_t *)v)->data); }

void print_path(void *v) {
  graph_path_t *path = (graph_path_t *)v;
  printf("from: %d ", *(int *)path->from->data);
  printf("to: %d ", *(int *)path->to->data);
  printf("weight: %lf", path->distance);
  printf("(init: %d)\n", *(int *)path->start->data);
}

int main() {
  graph_t *graph = new_graph(sizeof(int), 0);
  int value = 1;
  graph_add_vertex(graph, &value);

  int val = 2;
  vertex_t *neighboor = graph_add_vertex(graph, &val);

  int find = 1;
  vertex_t *vertex = graph_get_vertex_by_data(graph, &find, compare);

  find = 3;
  vertex_t *vertex2 = graph_add_vertex(graph, &find);

  find = 4;
  vertex_t *vertex3 = graph_add_vertex(graph, &find);

  graph_add_adjacency(vertex, neighboor, 1.0, 0);
  graph_add_adjacency(neighboor, vertex2, 1.0, 0);
  graph_add_adjacency(vertex2, vertex3, 2.0, 0);
  graph_add_adjacency(vertex, vertex3, 2.0, 0);

  list_t *l = get_min_distances(graph, compare);
  list_print(l, print_path);
  return 0;
}