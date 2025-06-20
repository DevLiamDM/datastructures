#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList;

LinkedList* createLinkedList();
void addToHead(LinkedList* list, void* data);
void addToTail(LinkedList* list, void* data);
void* removeFromHead(LinkedList* list);
void* removeFromTail(LinkedList* list);
void deleteNode(LinkedList* list, void* data, int (*cmpFunc)(void*, void*));
void printLinkedList(LinkedList* list, void (*printFunc)(void*));
void destroyLinkedList(LinkedList* list);

#endif
