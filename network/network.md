# Nertwork

Implementation of general usage functions to works with network context in C language.

this module aims to encapsulate network domain data structures and algorithms.

Avalaible structures:

* **ip_t**: structure to store an ip address

Available functions: 

* **new_ip**: create a new ip_t structure 
* **ip_from_string**: parses a string on format [0-256].[0-256].[0-256].[0-256] to ip_t structure
* **ip_print**: prints an ip structure on string format


Example of use: 

```c
  ip_t *ip = ip_from_string("255.255.255.0");
  ip_print(ip);
```