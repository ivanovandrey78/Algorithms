#pragma once 
#define MATH_FUNCTIONS_H

#include <iostream>

namespace mymath {
    double pow(double n,int rec);
    unsigned long Factorial(unsigned int n);
    int min(int a,int b); 
    int max(int a,int b);
    double sqrt(double n,int maxIterations = 3);
    double ln(double x);
    bool isPrime(int n);
}