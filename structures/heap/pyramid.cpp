#include "pyramid.h"

void SiftDown(int* arr, int size, int i, HeapType type) {
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int target = i;
        
        switch (type) {
            case HeapType::kMinHeap:
                if (arr[left] < arr[target]) target = left;
                if (right < size && arr[right] < arr[target]) target = right;
                break;
            case HeapType::kMaxHeap:
                if (arr[left] > arr[target]) target = left;
                if (right < size && arr[right] > arr[target]) target = right;
                break;
        }
        
        if (target == i) break;
        std::swap(arr[i], arr[target]);
        i = target;
    }
}

// Overload
void SiftDown(int* arr, int size, int i) {
    HeapType type = DetectHeapType(arr, size);
    SiftDown(arr, size, i, type);
}

void SiftUp(int* arr, int size, int i, HeapType type) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        bool should_swap = false;
        
        switch (type) {
            case HeapType::kMinHeap:
                should_swap = arr[i] < arr[parent];
                break;
            case HeapType::kMaxHeap:
                should_swap = arr[i] > arr[parent];
                break;
        }
        
        if (!should_swap) break;
        std::swap(arr[i], arr[parent]);
        i = parent;
    }
}

// Overload
void SiftUp(int* arr, int size, int i) {
    HeapType type = DetectHeapType(arr, size);
    SiftUp(arr, size, i, type);
}

void BuildHeap(int* arr, int size, HeapType type) {
    for (int i = size / 2; i >= 0; i--) {
        SiftDown(arr, size, i, type);
    }
}

void BuildHeap(int* arr, int size) {
    HeapType type = DetectHeapType(arr, size);
    BuildHeap(arr, size, type);
}

bool IsHeap(int* arr, int size, HeapType type) {
    for (int i = 0; i < size / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        switch (type) {
            case HeapType::kMinHeap:
                if (left < size && arr[i] > arr[left]) return false;
                if (right < size && arr[i] > arr[right]) return false;
                break;
            case HeapType::kMaxHeap:
                if (left < size && arr[i] < arr[left]) return false;
                if (right < size && arr[i] < arr[right]) return false;
                break;
        }
    }
    return true;
}

bool IsHeap(int* arr, int size) {
    HeapType type = DetectHeapType(arr, size);
    return IsHeap(arr, size, type);
}

HeapType DetectHeapType(int* arr, int size) {
    if (size < 2) return HeapType::kMaxHeap;
    
    int i = 0;
    while (i < size - 1 && arr[i] == arr[i + 1]) { i++; }
    
    if (i >= size - 1) return HeapType::kMaxHeap;
    
    return (arr[i] > arr[i + 1]) ? HeapType::kMaxHeap : HeapType::kMinHeap;
}

void heapSort(int* arr, int size, HeapType type) {

    BuildHeap(arr, size, type);
    
    for (int i = size - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        SiftDown(arr, i, 0, type);
    }
}

void heapSort(int* arr, int size) {
    HeapType type = DetectHeapType(arr, size);
    heapSort(arr, size, type);
}