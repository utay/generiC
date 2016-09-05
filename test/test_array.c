#include "../src/array.h"
#include "test.h"

void array_add_test();

int main()
{
    gc_set_exit_on_failure(true);

    array_add_test();

    return gc_get_status();
}

void array_add_test()
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
