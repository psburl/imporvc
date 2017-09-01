#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../collections/collections.h"

char * string_append(char * string1, char * string2);
char * string_append_all(int quantity, ...);
list_t* string_split(char* string, const char* delimiter);


#include "string.c"

#endif