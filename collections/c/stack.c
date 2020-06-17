#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * creates a new stack of specified type size.
 * example: new_stack(sizeof(int)); creates a list of integer values
 */
stack_t *new_stack(size_t type_size) {
  stack_t *stack = malloc(sizeof(stack_t));
  assert(type_size > 0);
  stack->top = NULL;
  stack->type_size = type_size;
  stack->count = 0;
  return stack;
}

/**
 * push a value to the top of stack
 */
void stack_push(stack_t *stack, void *value) {
  node_t *element = (node_t *)malloc(sizeof(node_t));
  element->data = malloc(stack->type_size);
  element->next = NULL;
  memcpy(element->data, value, stack->type_size);
  if (stack->count == 0) {
    stack->top = element;
  } else {
    element->next = stack->top;
    stack->top = element;
  }
  stack->count++;
}

/**
 * get the value on top of stack and removes it
 */
node_t *stack_pop(stack_t *stack) {
  node_t *element = stack->top;
  stack->top = stack->top->next;
  stack->count--;
  return element;
}

/**
 * verifies if stack is empty
*/
int stack_empty(stack_t *stack) { return stack->count == 0; }

/**
 * prints stack values from the top to the bottom 
*/
void stack_print(stack_t *stack, void (*print)(void *)) {
  node_t *node = stack->top;
  while (node != NULL) {
    print(node->data);
    node = node->next;
  }
}