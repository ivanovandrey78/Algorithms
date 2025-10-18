#include "../include/pyramid.hpp"
#include "../include/functions.h"

void SiftDown(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        SiftDown(arr, n, largest);
    }
}

void CreateHeap(int* arr, int n) {
    for(int i = n/2;i >= 0;i--) {
        SiftDown(arr,n,i);
    }
}

bool IsHeap(int* arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[i]) {
            return false;
        }
        
        if (right < n && arr[right] > arr[i]) {
            return false;
        }
    }
    return true;
}