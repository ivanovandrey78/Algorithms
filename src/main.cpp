#include "../include/functions.h"
#include "../include/sorts.h"
#include "../include/pyramid.hpp"

int main()
{
    int arr[] = { 60 ,20 ,40 ,70, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    CreateHeap(arr,n);

    std::cout << "After heapifying array is \n";
    PrintMassive(arr, n);
  
    heapSort(arr, n);

    std::cout << "Sorted array is \n";
    PrintMassive(arr, n);

    return 0;
}