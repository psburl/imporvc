#include "../collections/collections.h"
#include "../string/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


ip_t* new_ip(Byte a, Byte b, Byte c, Byte d){

	ip_t* ip = malloc(sizeof(ip_t));
	ip->data[0] = a;
	ip->data[1] = b;
	ip->data[2] = c;
	ip->data[3] = d;
	return ip;
}

ip_t* ip_from_string(char* string){

	list_t* tokens = string_split(string, ".");

	node_t* node_a = list_get_element(tokens, 0);
	assert(node_a != NULL);
	node_t* node_b = list_get_element(tokens, 1);
	assert(node_b != NULL);
	node_t* node_c = list_get_element(tokens, 2);
	assert(node_c != NULL);
	node_t* node_d = list_get_element(tokens, 3);
	assert(node_d != NULL);

	int a = atoi((char*)node_a->data);
	int b = atoi((char*)node_b->data);
	int c = atoi((char*)node_c->data);
	int d = atoi((char*)node_d->data);

	return new_ip((Byte)a, (Byte)b, (Byte)c, (Byte)d);
}

void ip_print(ip_t* ip){

	printf("%d.%d.%d.%d\n", ip->data[0],
	 ip->data[1], ip->data[2], ip->data[3]);
}