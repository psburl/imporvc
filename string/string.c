#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../collections/collections.h"

char * string_append(char * string1, char * string2){

	char * string = malloc(strlen(string1)+strlen(string2));

    assert(string!=NULL);
		
   	sprintf(string, "%s%s", string1, string2);
   	return string;   
}

char * string_append_all(int quantity, ...){

	int counter;

	va_list valist;
	va_start(valist, quantity);

	char* string = va_arg(valist, char*);

	for (counter = 1; counter < quantity; counter++)
      string = string_append(string, va_arg(valist, char*));
	
   	va_end(valist);

   	return string;
}

list_t* string_split(char* string, const char* delimiter){

	char *copy = strdup(string);

	list_t* list = new_list(sizeof(char*)*3);
    char* token = strtok(copy, delimiter);   
    while (token != NULL)
    {
        list_append(list, token);
        token = strtok(NULL, delimiter);
    }
 
    return list;
}