#include "../collections/collections.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * creates a new string pointer concatenating string2 in the end of string1 argument
*/
char *string_append(char *string1, char *string2) {
  char *string = (char *)malloc(strlen(string1) + strlen(string2));
  assert(string != NULL);
  sprintf(string, "%s%s", string1, string2);
  return string;
}

/**
 * creates a new string pointer concatenating all char * passed arguments
 * @param int quantity: specifies how many strings will be passed
 * @return char*:  a string with all passed string arguments concatenated
 */
char *string_append_all(int quantity, ...) {
  int counter;
  va_list valist;
  va_start(valist, quantity);
  char *string = va_arg(valist, char *);
  for (counter = 1; counter < quantity; counter++) {
    string = string_append(string, va_arg(valist, char *));
  }
  va_end(valist);
  return string;
}

/**
 * explode a string based on a string delimiter
 * @param char* string: source string to be exploded
 * @param char* delimiter: string used to delimit explosion
 * @return list_t*: a string list of explosion elements
 */
list_t *string_split(char *string, const char *delimiter) {
  char *copy = strdup(string);
  list_t *list = new_list(sizeof(char *) * 3);
  char *token = strtok(copy, delimiter);
  while (token != NULL) {
    list_append(list, token);
    token = strtok(NULL, delimiter);
  }
  return list;
}
