#pragma once 
#define MATH_FUNCTIONS_H

#include <iostream>

namespace math {
    double pow(double n,int rec);

    unsigned long factorial(unsigned int n);

    int min(int a,int b); 

    int max(int a,int b);

    double sqrt(double n,int maxIterations = 3);

    double ln(double x);

    bool isPrime(int n);

    int gcd(int a, int b);
}