#include <stdio.h>

/**
 * prints a void pointer as an integer value
*/
void int_print(void *value) { printf("%d\n", *(int *)value); }

/**
 * prints a void pointer as ac char pointer value
*/
void char_pointer_print(void *value) { printf("%s\n", (char *)value); }