#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include <stdio.h>

typedef struct queue_t {
  node_t *head;
  node_t *tail;
  size_t type_size;
  int count;
} queue_t;

queue_t *new_queue(size_t type_size);
void queue_insert(queue_t *queue, void *value);
node_t *queue_get(queue_t *queue);
void queue_print(queue_t *queue, void (*print)(void *));

#include "../c/queue.c"

#endif