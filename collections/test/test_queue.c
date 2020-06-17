#include "../collections.h"

void print(void *value) { printf("%d->", *(int *)value); }
/**
 * executes queue_t defined functions to detected behavior
*/
int main() {
	printf("creating queue of integers...\n");
  queue_t *queue = new_queue(sizeof(int));
  int value = 1;
	printf("enqueuing value %d to list\n", value);
  queue_insert(queue, &value);
  value = 2;
	printf("enqueuing value %d to list\n", value);
  queue_insert(queue, &value);
	printf("printing queue: ");
	queue_print(queue, print);
	printf("\n");
}