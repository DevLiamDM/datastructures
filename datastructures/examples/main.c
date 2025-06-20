#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/linked_list.h"
#include "../include/doubly_linked_list.h"
#include "../include/tree.h"
#include "../include/hashmap.h"
#include "../include/utils.h"

int main() {
    int* a = malloc(sizeof(int)); *a = 10;
    int* b = malloc(sizeof(int)); *b = 20;

    Stack* stack = createStack();
    push(stack, a);
    push(stack, b);
    printStack(stack, printInt);
    destroyStack(stack);

    Queue* queue = createQueue();
    enqueue(queue, a);
    enqueue(queue, b);
    printQueue(queue, printInt);
    destroyQueue(queue);

    LinkedList* list = createLinkedList();
    addToHead(list, a);
    addToTail(list, b);
    printLinkedList(list, printInt);
    destroyLinkedList(list);

    DoublyLinkedList* dlist = createDoublyLinkedList();
    addFirst(dlist, a);
    addLast(dlist, b);
    printDoublyLinkedList(dlist, printInt);
    destroyDoublyLinkedList(dlist);

    Tree* tree = createTree(intCompare);
    addTreeNode(tree, a);
    addTreeNode(tree, b);
    printTree(tree, printInt);
    freeTree(tree);

    HashMap* map = createHashMap(intHash, intCompare);
    insertHashMap(map, a, b);
    printHashMap(map, printKeyValue);
    destroyHashMap(map);

    free(a); free(b);
    return 0;
}
