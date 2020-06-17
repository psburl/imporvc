# collections 

Generic implementation of data the structures below: 

* list
* queue
* stack

## list ## 
>type: list_t

Available functions: 

* **new_list**: creates a new list of specified type size.
* **list_append**: adds a value to the end of list
* **list_prepend**: adds a value to the head of list
* **list_print**: prints list values from head to tail position
* **list_inverse_print**: prints list values from tail to head position
* **list_get_element**: gets list value persisted on specified position starting by 0.
* **list_remove_element**: removes list element persisted on specified position starting by 0.
* **list_get_by_data**: get list element which value matches to specified argument where matching is specified by comparison function argument

Example of use: 

```c
  list_t *list = new_list(sizeof(int));
  int value = 1;
  list_append(list, &value);
  value = 3;
  list_prepend(list, &value);
  value = 1;
  list_remove_element(list, value);
  list_print(list, print);
```

## stack ##
>type: stack_t

Available functions: 

* **new_stack**: creates a new stack of specified type size.
* **stack_push**: pushs a value to the top of stack
* **stack_pop**: gets the value on top of stack and removes it
* **stack_empty**: verifies if stack is empty
* **stack_print**: prints stack values from the top to the bottom 

Example of use: 

```c
  stack_t *stack = new_stack(sizeof(int));
  int value = 1;
  stack_push(stack, &value);
  printf("%d\n", *((int *)stack_pop(stack)->data));
  if (stack_empty(stack)) {
    printf("stack current state: empty\n");
  }
```

## queue ##
>type: queue_t

Available functions:

* **new_queue**: creates a new queue of specified type size.
* **queue_insert**: inserts a value to the end of queue
* **queue_get**: gets the next queue value (head element) and removes it
* **queue_print**: prints queue values from head to tail position

Example of use: 

```c
  queue_t *queue = new_queue(sizeof(int));
  int value = 1;
  queue_insert(queue, &value);
  value = 2;
  queue_insert(queue, &value);
  queue_print(queue, print);
```