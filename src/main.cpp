#include "../include/functions.h"
#include "../include/sorts.h"
#include "../include/pyramid.hpp"

int main() {

    int n;
    int* arr = randomMassive(n,100);
    print_massive(arr,n);
    
    mergeSort(arr,n); 
    print_massive(arr,n);

    delete[] arr;
    return 0;
    
}