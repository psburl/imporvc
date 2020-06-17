#include "../collections.h"

void print(void *value) { printf("%d->", *(int *)value); }

/**
 * executes list_t defined functions to detected behavior
*/
int main() {
  printf("creating list of integers...\n");
  list_t *list = new_list(sizeof(int));
  int value = 1;
  printf("adding value %d to list\n", value);
  list_append(list, &value);
  value = 2;
  printf("adding value %d to list\n", value);
  list_append(list, &value);
  value = 3;
  printf("adding value %d to list\n", value);
  list_prepend(list, &value);
  value = 1;
  printf("removing value %d from list\n", value);
  list_remove_element(list, value);
  printf("printing list: ");
  list_print(list, print);
  printf("\n");
}