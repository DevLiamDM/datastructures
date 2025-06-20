#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;

Queue* createQueue();
void enqueue(Queue* queue, void* data);
void* dequeue(Queue* queue);
void* front(Queue* queue);
int isQueueEmpty(Queue* queue);
void destroyQueue(Queue* queue);
void printQueue(Queue* queue, void (*printFunc)(void*));

#endif
