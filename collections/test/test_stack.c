#include "../collections.h"

/**
 * executes stack_t defined functions to detected behavior
*/
int main() {
  printf("creating stack of integers..\n");
  stack_t *stack = new_stack(sizeof(int));
  int value = 1;
	printf("pushing value 1 to stack..\n");
  stack_push(stack, &value);
	printf("popping top value from stack..\n");
  printf("value popped: %d\n", *((int *)stack_pop(stack)->data));
  if (stack_empty(stack)) {
    printf("stack current state: empty\n");
  }
}