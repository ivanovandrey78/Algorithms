#include "../include/pyramid.hpp"
#include "../include/functions.h"

void heapCreate(int* a,int n) {

    int* copy = new int[n]; // a -> copy
    for(int i = 0; i < n; i++) {
        copy[i] = a[i];
    }

    for(int i = n/2-1; i >= 0 ;i--) {
        siftDown(copy,n,i);
    }

    for(int i = 0; i < n; i++) {
        a[i] = copy[i]; 
    }
    delete[] copy;
}

// void siftDown(Heap* heap,size_t i) {

//     int left = 2*i+1;
//     int right = 2*i+2;
//     size_t j = left;

//     if (right <= heap->size && heap->elements[right] > heap->elements[left]) 
//         j = right;

//     if (heap->elements[i] > heap->elements[j])
//         return;

//     std::swap(heap->elements[i],heap->elements[j]);
// }

void siftDown(int* a,int n,size_t i) {

    int left = 2*i+1;
    int right = 2*i+2;
    int j = left;

    if (right < n && a[right] > a[left]) 
        j = right;

    if (a[i] > a[j])
        return;

    std::swap(a[i],a[j]);
    siftDown(a,n,j);
}

bool isHeap(Heap* heap) {
    return 1;
}