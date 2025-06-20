#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList* createDoublyLinkedList();
void addFirst(DoublyLinkedList* list, void* data);
void addLast(DoublyLinkedList* list, void* data);
void* removeFirst(DoublyLinkedList* list);
void* removeLast(DoublyLinkedList* list);
void deleteDoublyNode(DoublyLinkedList* list, void* data, int (*cmpFunc)(void*, void*));
void printDoublyLinkedList(DoublyLinkedList* list, void (*printFunc)(void*));
void destroyDoublyLinkedList(DoublyLinkedList* list);

#endif
