#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "node.h"

typedef struct list_t{

    node_t* head;
    node_t* tail;
    size_t type_size;
    int count;

}list_t;


list_t* new_list(size_t type_size);
void list_append(list_t* list, void* value);
void list_prepend(list_t* list, void* value);
void list_print(list_t* list, void (*print)(void*));
void list_inverse_print(list_t* list, void (*print)(void*));
node_t* list_get_element(list_t* list, int position);
void list_remove_element(list_t* list, int position);
node_t* list_get_by_data(list_t* list, void* data,  int (*compare)(void*, void*));

#include "../c/list.c"

#endif