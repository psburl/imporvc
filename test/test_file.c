#include "../io/io.h"
#include <stdio.h>

int main(){

 	char* file = file_read("test/file.txt");
 	printf("%s\n", file);   
    return 0;
}