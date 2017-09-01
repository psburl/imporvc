#include "../collections/collections.h"

int main() {
   
    stack_t* stack = new_stack(sizeof(int));

    int value = 1;
    stack_push(stack, &value);
    printf("%d\n", *((int*)stack_pop(stack)->data));

    if(stack_empty(stack))
    	printf("empty\n");
}