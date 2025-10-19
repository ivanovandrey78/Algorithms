#pragma once
#include <iostream>

enum class HeapType {
    kMinHeap,
    kMaxHeap,
};

// Main func
void SiftDown(int* arr, int size, int i, HeapType type);
void SiftUp(int* arr, int size, int i, HeapType type);
void BuildHeap(int* arr, int size, HeapType type);
bool IsHeap(int* arr, int size, HeapType type);
HeapType DetectHeapType(int* arr, int size);
void heapSort(int* arr, int size, HeapType type);

// Overloaded versions (kMinHeap by default)
void SiftDown(int* arr, int size, int i);
void SiftUp(int* arr, int size, int i);
void BuildHeap(int* arr, int size);
bool IsHeap(int* arr, int size);
void heapSort(int* arr, int size);