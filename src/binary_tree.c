#include "binary_tree.h"

BinaryTree* binary_tree_new()
{
    BinaryTree* tree = malloc(sizeof(BinaryTree));
    tree->root = malloc(sizeof(Node));
    tree->size = 0;
    return tree;
}

Node* binary_tree_search(Node *node, void *element)
{
    if (!node)
        return NULL;

    if (node->key == element) {
        return node;
    } else {
        if (element > node->key) {
            return binary_tree_search(element, node->right);
        } else if (element < node->key) {
            return binary_tree_search(element, node->left);
        } else {
            return NULL;
        }
    }
}

size_t binary_tree_size(Node *node)
{
    size_t size = 0;

    if (!node)
        return 0;

    ++size;
    if (node->right)
        size += binary_tree_size(node->right);
    if (node->left)
        size += binary_tree_size(node->left);

    return size;
}

void binary_tree_destroy(BinaryTree *bt)
{
    node_destroy_recursive(bt->root);
    free(bt);
}

void node_destroy_recursive(Node *node)
{
    if (!node)
        return;

    if (node->right)
        node_destroy_recursive(node->right);
    if (node->left)
        node_destroy_recursive(node->left);

    free(node);
}
