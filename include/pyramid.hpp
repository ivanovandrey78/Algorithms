#ifndef PYRAMID_H
#define PYRAMID_H
#define HEAP_CAPACITY 50

#include <iostream>

enum class HeapType {
    kMinHeap,
    kMaxHeap,
};

void HeapCreate(int* a,int n);
void SiftDown(int* a,int n,int i);
bool IsHeap(int* arr, int n);
void CreateHeap(int* arr, int n);

#endif