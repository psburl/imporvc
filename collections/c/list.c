#include "../collections.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * creates a new list of specified type size.
 * example: new_list(sizeof(int)); creates a list of integer values
 */
list_t *new_list(size_t type_size) {
  list_t *list = (list_t *)malloc(sizeof(list_t));
  assert(type_size > 0);
  list->head = NULL;
  list->tail = NULL;
  list->type_size = type_size;
  list->count = 0;
  return list;
}

/**
 * add a value to the end of list
 */
void list_append(list_t *list, void *value) {
  node_t *element = (node_t *)malloc(sizeof(node_t));
  element->data = (void *)malloc(list->type_size);
  element->next = NULL;
  element->previous = NULL;
  memcpy(element->data, value, list->type_size);

  if (list->count == 0) {
    list->head = list->tail = element;
  } else {
    list->tail->next = element;
    element->previous = list->tail;
    list->tail = element;
  }
  list->count++;
}

/**
 * add a value to the head of list
 */
void list_prepend(list_t *list, void *value) {
  node_t *element = (node_t*)malloc(sizeof(node_t));
  element->data = malloc(list->type_size);
  element->next = NULL;
  element->previous = NULL;
  memcpy(element->data, value, list->type_size);
  element->next = list->head;

  if (list->head != NULL) {
    list->head->previous = element;
  }
  list->head = element;
  if (!list->tail) {
    list->tail = list->head;
  }
  list->count++;
}

/**
 * prints list values from head to tail position
 */
void list_print(list_t *list, void (*print)(void *)) {
  node_t *node = list->head;
  while (node != NULL) {
    if (node->data != NULL) {
      print(node->data);
    }
    node = node->next;
  }
}

/**
 * prints list values from tail to head position
 */
void list_inverse_print(list_t *list, void (*print)(void *)) {
  node_t *node = list->tail;
  while (node != NULL) {
    if (node->data != NULL) {
      print(node->data);
    }
    node = node->previous;
  }
}

/**
 * get list value persisted on specified position starting by 0.
 */
node_t *list_get_element(list_t *list, int position) {
  if (position >= list->count) {
    return NULL;
  }
  int count = 0;
  node_t *element = list->head;
  while (count < position) {
    element = element->next;
    count++;
  }
  return element;
}

/**
 * removes list element persisted on specified position starting by 0.
 */
void list_remove_element(list_t *list, int position) {
  if (position >= list->count) {
    return;
  }
  int count = 0;
  node_t *element = list->head;
  while (count < position) {
    element = element->next;
    count++;
  }
  element->next->previous = element->previous;
  element->previous->next = element->next;
  free(element);
  count--;
}

/**
 * get list element which value matches to specified argument
 * where matching is specified by comparison function
 */
node_t *list_get_by_data(list_t *list, void *data,
                         int (*compare)(void *, void *)) {
  node_t *element = list->head;
  while (element != NULL) {
    if (compare(element->data, data))
      return element;
    element = element->next;
  }
  return NULL;
}
