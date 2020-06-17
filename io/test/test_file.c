#include "../io.h"
#include <stdio.h>

/**
 * executes io defined functions to detected behavior
 */
int main() {
  char *file = file_read("data/file.txt");
  printf("%s\n", file);
  return 0;
}