# improvc

A C library with several function implementations to encapsulate algorithms and data structures using C language without third-party dependencies.

The project contains the following function domains, where each one has your own documentation:

* [collections](collections/collections.md)
* [string](string/string.md)
* [network](network/network.md)
* [io](io/io.md)
* [graph](graph/graph.md)
  
## using the library ##

To use this library on your C or C++ program, just clone the repository on your project folder and start using importing the files.

Example of use: 

```c
#include "improvc.h"

void print_ip(void *ip) { ip_print((ip_t *)ip); }

int main() {
  list_t *list = new_list(sizeof(ip_t));
  ip_t *ip = ip_from_string("192.168.0.1");
  list_append(list, ip);
  ip = ip_from_string("192.168.0.2");
  list_prepend(list, ip);
  list_print(list, print_ip);
  return 0;
} 
```