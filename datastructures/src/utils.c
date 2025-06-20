#include <stdio.h>
#include "utils.h"

int intCompare(void* a, void* b) {
    return (*(int*)a) - (*(int*)b);
}

int intHash(void* a) {
    return (*(int*)a);
}

void printInt(void* data) {
    printf("%d ", *(int*)data);
}

void printKeyValue(void* key, void* value) {
    printf("[%d => %d] ", *(int*)key, *(int*)value);
}
