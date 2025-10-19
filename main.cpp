#include "math/math_functions.h"

#include <iostream>
#include <string>

const int MAX_SIZE = 100000;
int heap[MAX_SIZE];
int size = 0;

void SiftDown(int i) {
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        
        if (heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        
        if (smallest == i) break;
        std::swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

void SiftUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i] >= heap[parent]) break;
        std::swap(heap[i], heap[parent]);
        i = parent;
    }
}

void Insert(int value) {
    heap[size] = value;
    SiftUp(size);
    size++;
}

int GetMin() {
    int minVal = heap[0]; 
    heap[0] = heap[size - 1];
    size--;
    SiftDown(0);
    return minVal;
}

int GetMax() {

    int maxIndex = size / 2;
    for (int i = size / 2 + 1; i < size; i++) {
        if (heap[i] > heap[maxIndex]) {
            maxIndex = i;
        }
    }
    int maxVal = heap[maxIndex];
    
    heap[maxIndex] = heap[size - 1];
    size--;
    
    if (maxIndex < size) {
        SiftUp(maxIndex);
        SiftDown(maxIndex);
    }
    
    return maxVal;
}


int main() {
    std::cout << "🔍 Test 1" << std::endl;
    
    // Testируем по одному
    std::cout << "🔍 Test 2: fact 5... ";
    std::cout << mymath::factorial(5) << std::endl;
    
    std::cout << "🔍 Test 3: simple num... ";
    std::cout << mymath::isPrime(7) << std::endl;
    
    std::cout << "🔍 Test 4: LN... ";
    std::cout << mymath::ln(2.0) << std::endl;  // ⚠️ Если зависнет здесь - проблема в ln!
    
    std::cout << "✅ All Tests!" << std::endl;
    return 0;
}