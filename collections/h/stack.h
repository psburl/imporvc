#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "node.h"

typedef struct ppstack_t{

    node_t* top;
    size_t type_size;
    int count;

}pstack_t;

pstack_t* new_stack(size_t type_size);
void stack_push(pstack_t* stack, void* value);
node_t* stack_pop(pstack_t* stack);
int stack_empty(pstack_t* stack);
void stack_print(pstack_t* stack, void (*print)(void*));

#include "../c/stack.c"

#endif