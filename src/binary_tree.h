#ifndef GENERIC_BT_H
#define GENERIC_BT_H

#include "common.h"
#include "array.h"

struct node_s {
    struct node_s *right;
    struct node_s *left;
    void *key;
};
typedef struct node_s Node;

typedef struct {
    Node *root;
    size_t size;
} BinaryTree;

BinaryTree* binary_tree_new();
Node* binary_tree_search(Node *node, void *element);
size_t binary_tree_size(Node *node);
void binary_tree_destroy(BinaryTree *bt);
void node_destroy_recursive(Node *node);

#endif // GENERIC_BT_H
