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


void insertElement(int arr[], int& size, int position, int value) {

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    size++;
}

int main() {
    // const int MAX_N = 100000;
    // int n;
    // std::cin >> n;
    
    // int chart[MAX_N];  
    // int chartSize = 0; 
    
    // for (int i = 0; i < n; i++) {
    //     int rating;
    //     std::cin >> rating;
        

    //     int position = binarySearchRight(chart, chartSize, rating);

    //     std::cout << position << " ";
        
    //     insertElement(chart, chartSize, position, rating);
    // }
    
    // std::cout << std::endl;
    // return 0;
    std::cout << '\n';

    int n;
    int* arr = RandomMassive(n,100);
    PrintMassive(arr,n);

    CreateHeap(arr,n);
    PrintMassive(arr,n);

    std::cout << "Massive is heap: " << IsHeap(arr,n) << '\n';

    delete[] arr;
    std::cout << '\n';
    return 0;
}