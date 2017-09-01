#include <stdio.h>

void int_print(void* value){
	printf("%d\n", *(int*)value);
}

void char_pointer_print(void* value){
	printf("%s\n", (char*)value);
}