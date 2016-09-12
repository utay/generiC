#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include "common.h"

typedef struct {
    size_t   size;
    size_t   capacity;
    float    exp_factor;
    void   **buffer;
} Array;

typedef struct {
    size_t capacity;
    float exp_factor;
} ArrayConf;

Array* array_new(ArrayConf *conf);
Error array_add(Array *array, void *element);
Error expand_capacity(Array *array);
Error array_remove(Array *array, void *element);
Error array_remove_last(Array *array);
void* array_get_last(Array *array);
Error array_index_of(Array *array, void *element, size_t *index);
size_t array_contains(Array *array, void *element);
size_t array_size(Array *array);
size_t array_capacity(Array *array);
void array_destroy(Array *array);
void array_print(Array *array, size_t begin, size_t end);

#endif // GENERIC_ARRAY_H
