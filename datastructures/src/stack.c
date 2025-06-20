#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

struct Stack {
    StackNode* top;
};

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, void* data) {
    StackNode* node = malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

void* pop(Stack* stack) {
    if (!stack->top) return NULL;
    StackNode* temp = stack->top;
    void* data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void* peek(Stack* stack) {
    return stack->top ? stack->top->data : NULL;
}

int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

void destroyStack(Stack* stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

void printStack(Stack* stack, void (*printFunc)(void*)) {
    StackNode* current = stack->top;
    while (current) {
        printFunc(current->data);
        current = current->next;
    }
}
