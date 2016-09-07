# generiC
A simple library of generic C data structures.

## Examples

```c
// Create a new array

// Default configuration
Array *array = array_new(NULL);

// OR

// Custom configuration
ArrayConf conf = { .capacity = 100, .exp_factor = 2.5 };
Array *array = array_new(conf);

char *str = "generiC data structures are cool!";

// Add an element
Error err = array_add(array, str);
if (err) {
  // something went wrong
  ...
}

// Remove an element
Error err = array_remove(array, str);
if (err) {
  // something went wrong
  ...
}

// Destroy and free
array_destroy(array);
```
