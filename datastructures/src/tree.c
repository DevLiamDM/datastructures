#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree* createTree(int (*cmpFunc)(void*, void*)) {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    tree->cmpFunc = cmpFunc;
    return tree;
}

TreeNode* createTreeNode(void* data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

static TreeNode* insert(TreeNode* root, void* data, int (*cmpFunc)(void*, void*)) {
    if (!root) return createTreeNode(data);
    if (cmpFunc(data, root->data) < 0)
        root->left = insert(root->left, data, cmpFunc);
    else
        root->right = insert(root->right, data, cmpFunc);
    return root;
}

void addTreeNode(Tree* tree, void* data) {
    tree->root = insert(tree->root, data, tree->cmpFunc);
}

static void inOrder(TreeNode* node, void (*printFunc)(void*)) {
    if (!node) return;
    inOrder(node->left, printFunc);
    printFunc(node->data);
    inOrder(node->right, printFunc);
}

void printTree(Tree* tree, void (*printFunc)(void*)) {
    inOrder(tree->root, printFunc);
}

static void freeTreeNode(TreeNode* node) {
    if (!node) return;
    freeTreeNode(node->left);
    freeTreeNode(node->right);
    free(node);
}

void freeTree(Tree* tree) {
    freeTreeNode(tree->root);
    free(tree);
}
