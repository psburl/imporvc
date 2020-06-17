# string

Implementation of general usage functions to works with strings in C language using char pointer abstraction

Available functions: 

* **string_append**: creates a new string pointer concatenating 2 string arguments
* **string_append_all**: creates a new string pointer concatenating all string arguments
* **string_split**: explodes a string based on a string delimiter


Example of use: 

```c
  string_append("1", "2");
  string_append_all(3, "1", "2", "3");
  string_append_all(4, "1", "2", "3", "4");
  list_t *list = string_split("1,2", ",");
  list_print(list, char_pointer_print);
```