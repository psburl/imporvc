#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* file_read(char* directory);

#include "../c/file.c"

#endif