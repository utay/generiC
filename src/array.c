#include "array.h"

#define DEFAULT_CAPACITY 8
#define DEFAULT_EXPANSION_FACTOR 2

Array* array_new(ArrayConf *conf)
{
    Array *array = calloc(1, sizeof(Array));

    size_t capacity;
    float exp_factor;

    if (conf == NULL) {
        capacity = DEFAULT_CAPACITY;
        exp_factor = DEFAULT_EXPANSION_FACTOR;
    }

    array->buffer     = malloc(capacity * sizeof(void*));
    array->exp_factor = exp_factor;
    array->capacity   = capacity;

    return array;
}

Error array_add(Array *array, void *element)
{
    if (array->size >= array->capacity) {
        Error err = expand_capacity(array);
        if (err != NULL)
            return err;
    }

    array->buffer[array->size] = element;
    array->size++;

    return NULL;
}

Error expand_capacity(Array *array) {
    if (array->capacity == CC_MAX_ELEMENTS)
        return "Max capacity";

    array->capacity *= array->exp_factor;
    array->buffer = realloc(array->buffer, array->capacity * sizeof(void*));

    return NULL;
}

Error array_remove(Array *array, void *element) {
    bool present = false;

    for (size_t i = 0; i < array->size; ++i) {
        if (array->buffer[i] == element) {
            array->buffer[i] = NULL;
            present = true;
        }
    }

    if (!present)
        return "Element not found";

    return NULL;
}

void array_destroy(Array *array) {
    free(array->buffer);
    free(array);
}
