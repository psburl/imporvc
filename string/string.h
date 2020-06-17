#ifndef STRING_H
#define STRING_H

#include "../collections/collections.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_append(char *string1, char *string2);
char *string_append_all(int quantity, ...);
list_t *string_split(char *string, const char *delimiter);

#include "string.c"

#endif