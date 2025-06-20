#include <stdlib.h>
#include "doubly_linked_list.h"

typedef struct DNode {
    void* data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

struct DoublyLinkedList {
    DNode* head;
    DNode* tail;
};

DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    list->head = list->tail = NULL;
    return list;
}

void addFirst(DoublyLinkedList* list, void* data) {
    DNode* node = malloc(sizeof(DNode));
    node->data = data;
    node->prev = NULL;
    node->next = list->head;
    if (list->head) list->head->prev = node;
    else list->tail = node;
    list->head = node;
}

void addLast(DoublyLinkedList* list, void* data) {
    DNode* node = malloc(sizeof(DNode));
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail) list->tail->next = node;
    else list->head = node;
    list->tail = node;
}

void* removeFirst(DoublyLinkedList* list) {
    if (!list->head) return NULL;
    DNode* temp = list->head;
    void* data = temp->data;
    list->head = temp->next;
    if (list->head) list->head->prev = NULL;
    else list->tail = NULL;
    free(temp);
    return data;
}

void* removeLast(DoublyLinkedList* list) {
    if (!list->tail) return NULL;
    DNode* temp = list->tail;
    void* data = temp->data;
    list->tail = temp->prev;
    if (list->tail) list->tail->next = NULL;
    else list->head = NULL;
    free(temp);
    return data;
}

void deleteDoublyNode(DoublyLinkedList* list, void* data, int (*cmpFunc)(void*, void*)) {
    DNode* current = list->head;
    while (current) {
        if (cmpFunc(current->data, data) == 0) {
            if (current->prev) current->prev->next = current->next;
            else list->head = current->next;
            if (current->next) current->next->prev = current->prev;
            else list->tail = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
}

void printDoublyLinkedList(DoublyLinkedList* list, void (*printFunc)(void*)) {
    DNode* current = list->head;
    while (current) {
        printFunc(current->data);
        current = current->next;
    }
}

void destroyDoublyLinkedList(DoublyLinkedList* list) {
    while (list->head) {
        removeFirst(list);
    }
    free(list);
}
