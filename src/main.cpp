#include "../include/functions.h"
#include "../include/sorts.h"
#include "../include/pyramid.hpp"

#include <iostream>

int binarySearchRight(int arr[], int size, int target) {
    int left = 0;
    int right = size;  
    
    while (left < right) {
        int mid = left + (right - left) / 2; // избежание пополнения
        
        if (arr[mid] <= target) {

            left = mid + 1;
        } else {

            right = mid;
        }
    }
    
    return left;
}

int main() {

    std::cout << '\n';

    int n;
    int* arr = RandomMassive(n,100);
    PrintMassive(arr,n);

    HeapSort(arr,n);
    PrintMassive(arr,n);

    std::cout << "Massive is heap: " << IsHeap(arr,n) << '\n';

    delete[] arr;
    std::cout << '\n';
    return 0;

}