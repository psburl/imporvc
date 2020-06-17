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