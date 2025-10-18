#ifndef PYRAMID_H
#define PYRAMID_H
#define HEAP_CAPACITY 50

#include <iostream>

enum Type {
    MAX_HEAP,
    MIN_HEAP,
};

struct Heap {
    int size; // size now 
    int capacity; // capacity in all 
    int elements[HEAP_CAPACITY];
    Type heapType;
};

void HeapCreate(int* a,int n);
void SiftDown(int* a,int n,int i);
bool IsHeap(int* arr, int n);
void CreateHeap(int* arr, int n);

#endif