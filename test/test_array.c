#include "../src/array.h"
#include "test.h"

void test_array_add();
void test_array_remove();
void test_array_index_of();
void test_array_size();
void test_array_capacity();

int main()
{
    gc_set_exit_on_failure(false);

    test_array_add();
    test_array_remove();
    test_array_index_of();
    test_array_size();
    test_array_capacity();

    return gc_get_status();
}

void test_array_add()
{
    Array *array = array_new(NULL);

    int a = 1;
    int b = 2;
    int c = 3;

    array_add(array, &a);
    array_add(array, &b);
    array_add(array, &c);

    gc_assert(array->buffer[0] == &a &&
            array->buffer[1] == &b &&
            array->buffer[2] == &c,
            gc_msg("array_add: Added elements not in the expected position"));

    array_destroy(array);
}

void test_array_remove()
{
    Array *array = array_new(NULL);

    int a = 1;

    array_add(array, &a);
    gc_assert(array->buffer[0] == &a,
            gc_msg("array_remove: Added element not in the expected position"));

    array_remove(array, &a);
    gc_assert(array->buffer[0] == NULL,
            gc_msg("array_remove: Added element not removed"));

    Error err = array_remove(array, &a);
    gc_assert(err != NULL,
            gc_msg("array_remove: Element found after being removed"));

    array_destroy(array);
}

void test_array_index_of()
{
    Array *array = array_new(NULL);

    size_t index;
    int a = 1;

    array_add(array, &a);
    array_index_of(array, &a, &index);

    gc_assert(index == 0,
            gc_msg("array_index_of: Element not in the expected position"));

    array_destroy(array);
}

void test_array_size()
{
    Array *array = array_new(NULL);

    int a = 1;

    for (size_t i = 0; i < 40; ++i) {
        array_add(array, &a);
    }

    gc_assert(array_size(array) == 40,
            gc_msg("array_size: Not expected size"));

    array_destroy(array);
}

void test_array_capacity()
{
    ArrayConf conf = { .exp_factor = 2, .capacity = 10 };
    Array *array = array_new(&conf);

    gc_assert(array_capacity(array) == 10,
            gc_msg("array_capacity: Not expected capacity"));
}
