#ifndef TREE_H
#define TREE_H

typedef struct Tree Tree;
typedef struct TreeNode TreeNode;

Tree* createTree(int (*cmpFunc)(void*, void*));
TreeNode* addTreeNode(Tree* tree, void* data);
TreeNode* findTreeNode(Tree* tree, void* data);
void deleteTreeNode(Tree* tree, void* data);
void printTreeInOrder(Tree* tree, void (*printFunc)(void*));
void printTreePreOrder(Tree* tree, void (*printFunc)(void*));
void printTreePostOrder(Tree* tree, void (*printFunc)(void*));
void destroyTree(Tree* tree);

#endif
