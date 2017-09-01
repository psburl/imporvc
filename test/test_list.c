#include "../collections/collections.h"

int main() {
   
    list_t* list = new_list(sizeof(int));
    int value = 1;
    list_append(list,&value);
    value = 2;
    list_append(list,&value);
    value = 3;
    list_prepend(list,&value);
   
   
    list_remove_element(list, 1);
    list_print(list);
}