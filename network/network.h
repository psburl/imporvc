#ifndef NETWORK_H
#define NETWORK_H

#include "../collections/collections.h"
#include <stdio.h>

#define Byte unsigned char

typedef struct ip_t {
  Byte data[4];
} ip_t;

ip_t *new_ip(Byte a, Byte b, Byte c, Byte d);
ip_t *ip_from_string(char *string);
void ip_print(ip_t *ip);

#include "network.c"

#endif