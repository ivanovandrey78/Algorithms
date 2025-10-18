#include "../include/functions.h"
#include "../include/sorts.h"
#include "../include/pyramid.hpp"

double Sqrt(int n) {
    if (n < 0) {
        std::cerr << "Number must be positive" << '\n';
        return 1;
    }

    double result = 0;
    
    int d = 1;
    while (d*d <= n) {
        if (d*d == n) return (double)d;
        d++;
    }

    double derivative = 1/(2*d);
    result = n - (n - d*d) * derivative;

    return result;
}

int main() {

    int n;
    int* arr = RandomMassive(n,100);

    PrintMassive(arr,n);

    // Sort start 
    CreateHeap(arr,n);
    PrintMassive(arr,n);
    if (IsHeap(arr,n)) {
        std::cout << "Massive is Heap" << '\n';
    } else {
        std::cout << "Massive is't Heap! Error code: 1";
        return 1;
    }

    // Functions with Heap
    HeapSort(arr,n);
    PrintMassive(arr,n);

    delete[] arr;
    return 0;
}