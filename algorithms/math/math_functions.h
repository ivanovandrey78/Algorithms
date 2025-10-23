#pragma once 
#define MATH_FUNCTIONS_H

#include <iostream>
#include <string>

namespace math {
    // Math constants
    constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944;
    constexpr double E = 2.718281828459045235360287471352662497757247093699959574966967;
    constexpr double LN2 = 0.693147180559945309417232121458176568075500134360255254120680;
    const double PI_2 = PI/2;  // pi/2
    const double PI_4 = PI/4;  // pi/4


    double pow(double n,int rec);

    unsigned long factorial(unsigned int n);

    int min(int a,int b); 

    int max(int a,int b);

    double sqrt(double n,int maxIterations = 3);

    double ln(double x);

    bool isPrime(int n);

    int gcd(int a, int b);

    double arctan(double x);
    double arctan2(double y, double x);

    int abs(int x);
    double abs(double x);

    double round(double x);

    std::string angle_string(double angle_rad, double tolerance = 1e-10);
}