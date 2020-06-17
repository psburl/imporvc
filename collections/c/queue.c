#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * creates a new queue of specified type size.
 * example: queue(sizeof(int)); creates a queue of integer values
 */
queue_t *new_queue(size_t type_size) {
  queue_t *queue = malloc(sizeof(queue_t));
  assert(type_size > 0);
  queue->head = NULL;
  queue->tail = NULL;
  queue->type_size = type_size;
  queue->count = 0;
  return queue;
}

/**
 * inserts a value to the end of queue
 */
void queue_insert(queue_t *queue, void *value) {
  node_t *element = malloc(sizeof(node_t));
  element->data = malloc(queue->type_size);
  element->next = NULL;
  memcpy(element->data, value, queue->type_size);
  if (queue->count == 0) {
    queue->head = queue->tail = element;
  }
  else {
    queue->tail->next = element;
    queue->tail = element;
  }
  queue->count++;
}

/**
 * gets the next queue value (head element) and removes it
 */
node_t *queue_get(queue_t *queue) {
  node_t *element = queue->head;
  queue->head = queue->head->next;
  return element;
}


/**
 * prints queue values from head to tail position
 */
void queue_print(queue_t *queue, void (*print)(void *)) {
  node_t *node = queue->head;
  while (node != NULL) {
    print(node->data);
    node = node->next;
  }
}