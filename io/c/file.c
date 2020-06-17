#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * reads a file stream and parses to a char pointer variable;
 * @param char * directory: file path to be reads
 * @return char *: string containing file content
*/
char *file_read(char *directory) {
  FILE *file = fopen(directory, "rb");
  char *code;
  int totalSize, character, currentPosition = 0;
  assert(file != NULL);
  fseek(file, 0L, SEEK_END);
  totalSize = ftell(file);
  rewind(file);
  fseek(file, 0, SEEK_SET);
  code = malloc(totalSize);
  while ((character = fgetc(file)) != EOF) {
    code[currentPosition++] = (char)character;
  }
  fclose(file);
  code[currentPosition] = '\0';
  return code;
}