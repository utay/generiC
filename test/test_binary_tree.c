#include "../src/binary_tree.h"
#include "test.h"

void test_binary_tree_new();
void test_binary_tree_search();
void test_binary_tree_size();

int main()
{
    gc_set_exit_on_failure(false);

    test_binary_tree_new();
    test_binary_tree_search();
    test_binary_tree_size();

    return gc_get_status();
}

void test_binary_tree_new()
{
    BinaryTree *bt = binary_tree_new();

    gc_assert(bt != NULL,
            gc_msg("binary_tree_new: Binary tree is NULL"));

    binary_tree_destroy(bt);
}

void test_binary_tree_search()
{
}

void test_binary_tree_size()
{
}
