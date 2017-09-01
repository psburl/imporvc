#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "../collections.h"


list_t* new_list(size_t type_size){

    list_t* list = malloc(sizeof(list_t));
    assert(type_size > 0);
    list->head = NULL;
    list->tail = NULL;
    list->type_size = type_size;
    list->count = 0;
    return list;
}

void list_append(list_t* list, void* value){
   
    node_t* element =  malloc(sizeof(node_t));
    element->data = malloc(list->type_size);
    element->next = NULL;
    element->previous = NULL;
   
    memcpy(element->data, value, list->type_size);
   
    if(list->count == 0)
        list->head = list->tail = element;
    else{
        list->tail->next = element;
        element->previous = list->tail;       
        list->tail = element;
    }
    list->count++;
}

void list_prepend(list_t* list, void* value){

    node_t* element =  malloc(sizeof(node_t));
    element->data = malloc(list->type_size);
    element->next = NULL;
    element->previous = NULL;
   
    memcpy(element->data, value, list->type_size);
   
    element->next = list->head;
   
    if(list->head != NULL)
        list->head->previous = element;
   
    list->head = element;
   
    if(!list->tail)
        list->tail = list->head;
    list->count++;
}

void list_print(list_t* list, void (*print)(void*)){

    node_t* node = list->head;
   
    while(node != NULL){
        print(node->data);
        node = node->next;
    }
}

void list_inverse_print(list_t* list, void (*print)(void*)){
   
    node_t* node = list->tail;
   
    while(node != NULL){
        print(node->data);
        node = node->previous;
    }
}

node_t* list_get_element(list_t* list, int position){
   
    if(position >= list->count)
        return NULL;
   
    int count = 0;
    node_t* element = list->head;
    while(count < position){
        element = element->next;
        count++;
    }
       
    return element;
}

void list_remove_element(list_t* list, int position){
   
    if(position >= list->count)
        return;
   
    int count = 0;
    node_t* element = list->head;
    while(count < position){
        element = element->next;
        count++;
    }
   
    element->next->previous = element->previous;
    element->previous->next = element->next;
   
    free(element);
    count--;
}