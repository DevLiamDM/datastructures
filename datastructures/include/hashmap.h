#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

typedef struct HashMap HashMap;

HashMap* createHashMap(size_t size, unsigned int (*hashFunc)(void*), int (*cmpFunc)(void*, void*));
void hashMapPut(HashMap* map, void* key, void* value);
void* hashMapGet(HashMap* map, void* key);
void hashMapRemove(HashMap* map, void* key);
int hashMapContainsKey(HashMap* map, void* key);
void destroyHashMap(HashMap* map);
void printHashMap(HashMap* map, void (*printKey)(void*), void (*printValue)(void*));

#endif
