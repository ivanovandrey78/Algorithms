#pragma once
#include <iostream>

#define PYRAMID_H
#define HEAP_CAPACITY 50

enum class HeapType {
    kMinHeap,
    kMaxHeap,
};

void HeapCreate(int* a,int n);
void SiftDown(int* a,int n,int i);
bool IsHeap(int* arr, int n);
void CreateHeap(int* arr, int n);
void heapSort(int* arr, int n);