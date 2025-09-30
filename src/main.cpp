#include "../include/functions.h"
#include "../include/sorts.h"
#include "../include/pyramid.hpp"

#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

uint32_t cur = 0;

uint32_t nextRand24(uint32_t a, uint32_t b) {
    cur = cur * a + b;
    return cur >> 8;
}

uint32_t nextRand32(uint32_t a, uint32_t b) {
    uint32_t x = nextRand24(a, b);
    uint32_t y = nextRand24(a, b);
    return (x << 8) ^ y;
}

uint32_t quickSelect(uint32_t arr[], int n, int k) {
    k--; // т.к. счёт треков начинается с 1
    int left = 0, right = n - 1;
    
    while (left < right) {
        // рандомный опорный элемент
        int pivotIndex = left + rand() % (right - left + 1);
        uint32_t pivot = arr[pivotIndex];
        
        int i = left - 1;
        int j = right + 1;
        
        while (true) {
            do { i++; } while (arr[i] < pivot);
            do { j--; } while (arr[j] > pivot);
            
            if (i >= j) break;
            
            uint32_t temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
        int pos = j;
        
        if (k <= pos) {
            right = pos;
        } else {
            left = pos + 1;
        }
    }
    
    return arr[left];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));

    uint32_t n, k, a, b;
    cin >> n >> k >> a >> b;

    uint32_t arr[n];

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = nextRand32(a, b);
    }

    cout << quickSelect(arr, n, k) << "\n";

    return 0;
}