#include "../../collections/collections.h"
#include "../../io/io.h"
#include "../string.h"
#include <stdio.h>

/**
 * executes string defined functions to detected behavior
*/
int main() {
  printf("string_append of 1 and 2: %s\n", string_append("1", "2"));
  printf("string_append_all of 1, 2 and 3 %s\n",
         string_append_all(3, "1", "2", "3"));
  list_t *list = string_split("1,2", ",");
  printf("printing splited string: \n");
  list_print(list, char_pointer_print);
}
