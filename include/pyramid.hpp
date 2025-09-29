#ifndef PYRAMID_H
#define PYRAMID_H

#include <iostream>

enum type {
    MAX_HEAP,
    MIN_HEAP,
};

struct Heap {
    int size;
    int* elements;
    int top = *elements;
};

void heapCreate(int* a,int n);
void siftDown(int* a,int n,size_t i);

#endif