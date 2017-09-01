#include "../collections/collections.h"

int main() {
   
    queue_t* queue = new_queue(sizeof(int));
   
    int value = 1;
    queue_insert(queue, &value);
    value = 2;
    queue_insert(queue, &value);
   
    printf("%d\n", *(int*)queue_get(queue)->data);
}