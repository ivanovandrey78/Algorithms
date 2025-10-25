#pragma once
#define SORT_H

#include <iostream>

enum class PartitionType { 
    kPartitionHoare,
    kPartitionRandom, // based on Hoare Partition
    kPartitionLomuto,
};

// main functions
void insertSort(int* array, int n,int& c);
void bubbleSort(int* arr, int asize);
void selectionSort(int* a,int n);
void mergeSort(int* a,size_t sizeA);

// quick sort (all helper functions and main func)
int PartitionLomuto(int* a, int start, int end);
int PartitionHoare(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void quickSort(int* a, int start, int end,PartitionType partType = PartitionType::kPartitionRandom);

// heap 
void heapSort(int* arr, int n);

// helpers for sorts 
bool isSorted(int* arr,int n);
int* merge(int* a,int nA, int* b,int nB,int& n);