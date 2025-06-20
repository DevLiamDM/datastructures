#include <stdlib.h>
#include "hashmap.h"

typedef struct HashNode {
    void* key;
    void* value;
    struct HashNode* next;
} HashNode;

struct HashMap {
    HashNode* buckets[HASHMAP_SIZE];
    int (*hashFunc)(void*);
    int (*cmpFunc)(void*, void*);
};

HashMap* createHashMap(int (*hashFunc)(void*), int (*cmpFunc)(void*, void*)) {
    HashMap* map = malloc(sizeof(HashMap));
    for (int i = 0; i < HASHMAP_SIZE; i++) map->buckets[i] = NULL;
    map->hashFunc = hashFunc;
    map->cmpFunc = cmpFunc;
    return map;
}

void insertHashMap(HashMap* map, void* key, void* value) {
    int index = map->hashFunc(key) % HASHMAP_SIZE;
    HashNode* node = map->buckets[index];
    while (node) {
        if (map->cmpFunc(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = map->buckets[index];
    map->buckets[index] = node;
}

void* getHashMap(HashMap* map, void* key) {
    int index = map->hashFunc(key) % HASHMAP_SIZE;
    HashNode* node = map->buckets[index];
    while (node) {
        if (map->cmpFunc(node->key, key) == 0) return node->value;
        node = node->next;
    }
    return NULL;
}

void deleteHashMap(HashMap* map, void* key) {
    int index = map->hashFunc(key) % HASHMAP_SIZE;
    HashNode *node = map->buckets[index], *prev = NULL;
    while (node) {
        if (map->cmpFunc(node->key, key) == 0) {
            if (prev) prev->next = node->next;
            else map->buckets[index] = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void destroyHashMap(HashMap* map) {
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        HashNode* node = map->buckets[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map);
}

void printHashMap(HashMap* map, void (*printFunc)(void*, void*)) {
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        HashNode* node = map->buckets[i];
        while (node) {
            printFunc(node->key, node->value);
            node = node->next;
        }
    }
}
