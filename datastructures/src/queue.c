#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct QueueNode {
    void* data;
    struct QueueNode* next;
} QueueNode;

struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, void* data) {
    QueueNode* node = malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    if (!queue->rear) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

void* dequeue(Queue* queue) {
    if (!queue->front) return NULL;
    QueueNode* temp = queue->front;
    void* data = temp->data;
    queue->front = queue->front->next;
    if (!queue->front) queue->rear = NULL;
    free(temp);
    return data;
}

void* front(Queue* queue) {
    return queue->front ? queue->front->data : NULL;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void destroyQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void printQueue(Queue* queue, void (*printFunc)(void*)) {
    QueueNode* current = queue->front;
    while (current) {
        printFunc(current->data);
        current = current->next;
    }
}
