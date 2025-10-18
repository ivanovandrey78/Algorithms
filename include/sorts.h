#ifndef SORT_H
#define SORT_H

#include <iostream>

// other
void insertSort(int* array, int n,int& c);
void bubbleSort(int* arr, int asize);
void SelectionSort(int* a,int n);
int* merge(int* a,int nA, int* b,int nB,int& n);
void merge(int* res,int*a,size_t sizeA, int*b,size_t sizeB);
void MergeSort(int* a,size_t sizeA);

// quick 
int PartitionLomuto(int* a, int start, int end);
int PartitionHoare(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void quickSort(int* a, int start, int end,int partType);

// heap 
void HeapSort(int* arr,int n);

#endif