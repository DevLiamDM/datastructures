# 📚 C Data Structures Library

A modular and extensible C library for fundamental data structures: **Stack**, **Queue**, **Singly Linked List**, **Doubly Linked List**, **Binary Search Tree**, and **Hash Map**. Designed for educational purposes, rapid development, and integration into C projects.

---

## 📦 Supported Structures

- ✅ Stack (LIFO)
- ✅ Queue (FIFO)
- ✅ Singly Linked List
- ✅ Doubly Linked List
- ✅ Binary Search Tree (BST)
- ✅ Hash Map (Chaining-based)

---

## 🛠️ Build Instructions

Ensure you have `gcc` installed. Then simply run:

```bash
make
```
To execute the example:

```bash
./example
```
## ✨ Usage Example (main.c)
```bash
#include "stack.h"
#include "utils.h"

int* a = malloc(sizeof(int)); *a = 10;
Stack* s = createStack();
push(s, a);
printStack(s, printInt);
destroyStack(s);
free(a);
Each data structure follows a similar pattern: createX, addX, printX, destroyX.
```

## 🧰 Utility Functions (utils.c)

intCompare(void*, void*) — for sorting and comparison

intHash(void*) — simple hash function for integers

printInt(void*), printKeyValue(void*, void*) — helper print functions

## ⚙️ Dependencies
None! Pure ANSI C.

## 🚀 Extensibility
The library is designed to be flexible and reusable:

Uses void* for generic data support

External function pointers (cmpFunc, printFunc, hashFunc) enable custom behavior
