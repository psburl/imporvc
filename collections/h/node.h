#ifndef NODE_H
#define NODE_H


typedef struct node_t{

    void* data;
    struct node_t* next;
    struct node_t* previous;
   
}node_t;


#include "../c/node.c"

#endif