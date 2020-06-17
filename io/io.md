# IO

Implementation of input/output functions in C language to work with stdin and stdout

Avalaible structures:

Available functions: 

* **int_print**: prints a void pointer as an integer value
* **char_pointer_print**:  prints a void pointer as ac char pointer value
* **file_read**: reads a file stream and parses to a char pointer variable

Example of use: 

```c
  char *file = file_read("data/file.txt");
```