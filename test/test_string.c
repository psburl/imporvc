#include "../string/string.h"
#include "../collections/collections.h"
#include "../io/io.h"
#include <stdio.h>

int main() {
   
    printf("string_append: %s\n", string_append("1", "2"));
    printf("string_append_all: %s\n", string_append_all(3, "1", "2", "3"));

    list_t* list = string_split("1,2", ",");
    list_print(list, char_pointer_print);
}