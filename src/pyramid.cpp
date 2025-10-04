#include "../include/pyramid.hpp"
#include "../include/functions.h"

void SiftDown(int* a,int n,int i) {

    int left = 2*i+1;
    int right = 2*i+2;
    int j = left;

    if (right < n && a[right] > a[left]) 
        j = right;

    if (a[i] > a[j])
        return;

    std::swap(a[i],a[j]);
    SiftDown(a,n,j);
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