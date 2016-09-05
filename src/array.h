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
void array_destroy(Array *array);

#endif // GENERIC_ARRAY_H