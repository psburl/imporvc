#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

stack_t* new_stack(size_t type_size){

    stack_t* stack = malloc(sizeof(stack_t));
    assert(type_size > 0);
    stack->top = NULL;
    stack->type_size = type_size;
    stack->count = 0;
    return stack;
}

void stack_push(stack_t* stack, void* value){
  
    node_t* element =  malloc(sizeof(node_t));
    element->data = malloc(stack->type_size);
    element->next = NULL;
  
    memcpy(element->data, value, stack->type_size);
  
    if(stack->count == 0)
        stack->top = element;
    else{
        element->next = stack->top;
        stack->top = element;
    }
    stack->count++;
}

node_t* stack_pop(stack_t* stack){
  
    node_t* element = stack->top;
    stack->top = stack->top->next;
    stack->count--;
    return element;
}

int stack_empty(stack_t* stack){
    return stack->count==0;
}

void stack_print(stack_t* queue, void (*print)(void*)){
   
    node_t* node = queue->head;
   
    while(node != NULL){
        print(node->data);
        node = node->next;
    }
}