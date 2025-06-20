#include <stdlib.h>
#include "linked_list.h"

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
};

LinkedList* createLinkedList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void addToHead(LinkedList* list, void* data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
}

void addToTail(LinkedList* list, void* data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (!list->head) {
        list->head = node;
        return;
    }
    Node* current = list->head;
    while (current->next) current = current->next;
    current->next = node;
}

void* removeFromHead(LinkedList* list) {
    if (!list->head) return NULL;
    Node* temp = list->head;
    void* data = temp->data;
    list->head = temp->next;
    free(temp);
    return data;
}

void* removeFromTail(LinkedList* list) {
    if (!list->head) return NULL;
    Node *prev = NULL, *current = list->head;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    void* data = current->data;
    if (prev) prev->next = NULL;
    else list->head = NULL;
    free(current);
    return data;
}

void deleteNode(LinkedList* list, void* data, int (*cmpFunc)(void*, void*)) {
    Node *prev = NULL, *current = list->head;
    while (current) {
        if (cmpFunc(current->data, data) == 0) {
            if (prev) prev->next = current->next;
            else list->head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printLinkedList(LinkedList* list, void (*printFunc)(void*)) {
    Node* current = list->head;
    while (current) {
        printFunc(current->data);
        current = current->next;
    }
}

void destroyLinkedList(LinkedList* list) {
    while (list->head) {
        removeFromHead(list);
    }
    free(list);
}
