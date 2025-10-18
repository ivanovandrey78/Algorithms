#include "../include/sorts.h"
#include "../include/functions.h"
#include "../include/pyramid.hpp"

void insertSort(int* array, int n, int& comparisonСount) { // O(n^2)
    if (n == 0) { 
        comparisonСount = 0;
        return;
    }

    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0) {
            comparisonСount++; 
            if (array[j] > key) {
                array[j + 1] = array[j];
                j--;
            } else break;
        }

        array[j + 1] = key;
    }
}

void bubbleSort(int* arr, int asize) { // O(n^2)
    for (int i = 0; i < asize-1; i++) 
    {
        for (int j = 0; j < asize - i - 1 ; j++)
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
            }
    }       
}

void SelectionSort(int* a, int n) { // O(n^2)
    for (int i = 0; i < n-1; i++) {
        int indexNow = i; 
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[indexNow]) {
                indexNow = j;
            }
        }
        if (indexNow != i) {
            std::swap(a[i], a[indexNow]);
        }
    }
}

void merge(int* res,int*a,size_t sizeA,int*b,size_t sizeB) { // Simple merge with C-style
    
    int i=0,j=0;
    int indexNow = 0;
    
    while (i < sizeA && j < sizeB) {
        if (a[i] <= b[j]) {
            res[indexNow] = a[i];
            i++;
            indexNow++;
        }
        else {
            res[indexNow] = b[j];
            j++;
            indexNow++;
        }
    }
    while (i < sizeA) {
        res[indexNow] = a[i];
        indexNow++;
        i++;
    }
    while (j < sizeB) {
        res[indexNow] = b[j];
        indexNow++;
        j++;
    }
}

void MergeSort(int* a,size_t sizeA) { // O(nlogn)

    if (sizeA <= 1) 
    {
        return;
    }

    size_t mid = sizeA/2;
    int* left = new int[mid];
    int* right = new int[sizeA-mid];

    for (size_t i=0;i<mid;i++) 
    {
        left[i] = a[i];
    }
    for (size_t i = mid;i<sizeA;i++) 
    {
        right[i-mid] = a[i];
    }

    MergeSort(left,mid);
    MergeSort(right,sizeA-mid);

    merge(a,left,mid,right,sizeA-mid);

    delete[] left;
    delete[] right;
}

void HeapSort(int* arr,int n) {
    
    CreateHeap(arr,n);

    for(int i = 0; i > 0;i++) {
        std::swap(arr[0],arr[i]);
        SiftDown(arr,i,0);
    }
}

int PartitionLomuto(int* a, int start, int end) { // O(n^2)

    int pivot = a[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (a[j] <= pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }

    std::swap(a[i + 1], a[end]);
    return i + 1;
}

int PartitionHoare(int* arr, int low, int high) { // O(n^2)
    int pivot = arr[low];
    
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        
        do {
            j--;
        } while (arr[j] > pivot);
        
        if (i >= j) {
            return j;
        }
        std::swap(arr[i], arr[j]);
    }
}

int partition(int* arr, int low, int high) { // O(nlogn)

    int randomIndex = low + rand() % (high - low + 1);
    std::swap(arr[randomIndex], arr[high]);
    
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int* a, int start, int end,int partType) { // O(nlogn) or O(n^2)

    if (start < end) {
        int pivot;

        switch (partType) // pivot == 0 - random, 1 - Hoare, 2 - Lomuto 
        {
            case 0: {
                pivot = partition(a, start, end);
                break;
            }
            case 1: {
                pivot = PartitionHoare(a,start,end);
                break;
            }
            default: {
                pivot = PartitionLomuto(a,start,end);
                break;
            }
        }
        
        if (pivot > 0 && partType != 1) {
            quickSort(a, start, pivot-1,partType);
        } else {
            quickSort(a, start, pivot,partType);
        }

        quickSort(a, pivot + 1, end,partType);
    }
}