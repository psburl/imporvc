#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

queue_t* new_queue(size_t type_size){
   
    queue_t* queue = malloc(sizeof(queue_t));
    assert(type_size > 0);
    queue->head = NULL;
    queue->tail = NULL;
    queue->type_size = type_size;
    queue->count = 0;
    return queue;
}

void queue_insert(queue_t* queue, void* value){
   
    node_t* element =  malloc(sizeof(node_t));
    element->data = malloc(queue->type_size);
    element->next = NULL;
   
    memcpy(element->data, value, queue->type_size);
   
    if(queue->count == 0)
        queue->head = queue->tail = element;
    else{
        queue->tail->next = element;
        queue->tail = element;
    }
    queue->count++;
}

node_t* queue_get(queue_t* queue){
   
    node_t* element = queue->head;
    queue->head = queue->head->next;
    return element;
}

void queue_print(queue_t* queue){
   
    node_t* node = queue->head;
   
    while(node != NULL){
        printf("%d\n", *((int*)node->data));
        node = node->next;
    }
}