#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack* createStack();
void push(Stack* stack, void* data);
void* pop(Stack* stack);
void* peek(Stack* stack);
int isStackEmpty(Stack* stack);
void destroyStack(Stack* stack);
void printStack(Stack* stack, void (*printFunc)(void*));

#endif
