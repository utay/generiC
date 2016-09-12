#include "array.h"

#define DEFAULT_CAPACITY 8
#define DEFAULT_EXPANSION_FACTOR 2

Array* array_new(ArrayConf *conf)
{
    Array *array = malloc(sizeof(Array));

    size_t capacity;
    float exp_factor;

    if (!conf) {
        capacity = DEFAULT_CAPACITY;
        exp_factor = DEFAULT_EXPANSION_FACTOR;
    } else {
        capacity = conf->capacity;
        exp_factor = conf->exp_factor;
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
        if (err)
            return err;
    }

    array->buffer[array->size] = element;
    array->size++;

    return NULL;
}

Error expand_capacity(Array *array)
{
    if (array->capacity == CC_MAX_ELEMENTS)
        return "Error: Max capacity";

    array->capacity *= array->exp_factor;
    array->buffer = realloc(array->buffer, array->capacity * sizeof(void*));

    return NULL;
}

Error array_remove(Array *array, void *element)
{
    size_t index;

    Error err = array_index_of(array, element, &index);

    if (!err) {
        array->buffer[index] = NULL;
        if (index != array->size - 1) {
            size_t block_size = (array->size - index) * sizeof(void*);

            memmove(&(array->buffer[index]),
                    &(array->buffer[index + 1]),
                    block_size);
        }
        --array->size;
        return NULL;
    }

    return err;
}

Error array_remove_last(Array *array)
{
    if (!array->size)
        return "Error: Array is empty";

    return array_remove(array, array->buffer[array->size - 1]);
}

void* array_get_last(Array *array)
{
    if (!array->size)
        return NULL;

    return array->buffer[array->size - 1];
}

Error array_index_of(Array *array, void *element, size_t *index)
{
    for (size_t i = 0; i < array->size; ++i) {
        if (array->buffer[i] == element) {
            *index = i;
            return NULL;
        }
    }

    return "Error: Element not found";
}

size_t array_contains(Array *array, void *element)
{
    size_t nb_matches = 0;

    for (size_t i = 0; i < array->size; ++i) {
        if (array->buffer[i] == element) {
            ++nb_matches;
        }
    }

    return nb_matches;
}

size_t array_size(Array *array)
{
    return array->size;
}

size_t array_capacity(Array *array)
{
    return array->capacity;
}

void array_destroy(Array *array)
{
    free(array->buffer);
    free(array);
}

void array_print(Array *array, size_t begin, size_t end)
{
    if (begin > end || end > array->size)
        return;

    for (size_t i = begin; i < end; ++i) {
        printf("[%zu] %s\n", i, (char*) array->buffer[i]);
    }
}
