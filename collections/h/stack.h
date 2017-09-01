#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "node.h"

typedef struct stack_t{

    node_t* top;
    size_t type_size;
    int count;

}stack_t;

stack_t* new_stack(size_t type_size);
void stack_push(stack_t* stack, void* value);
node_t* stack_pop(stack_t* stack);
int stack_empty(stack_t* stack);

#include "../c/stack.c"

#endif