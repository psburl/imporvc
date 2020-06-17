#include "../../collections/collections.h"
#include "../network.h"
#include <stdio.h>


/**
 * executes network defined functions to detected behavior
*/
int main() {
  printf("creating an ip structure from a string...\n");
  ip_t *ip = ip_from_string("255.255.255.0");
  printf("printing created ip: ");
  ip_print(ip);
  return 0;
}