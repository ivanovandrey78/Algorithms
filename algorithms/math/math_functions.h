#pragma once 
#define MATH_FUNCTIONS_H

#include <iostream>
#include <string>

namespace math {

    // ================================
    //         Math constants
    // ================================
    constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944;
    constexpr double E = 2.718281828459045235360287471352662497757247093699959574966967;
    constexpr double LN2 = 0.693147180559945309417232121458176568075500134360255254120680;
    const double PI_2 = PI/2;  // pi/2
    const double PI_4 = PI/4;  // pi/4
    const double PI_6 = PI/6;  // pi/6
    
    // ================================
    // Ranks and combinatorial functions
    // ================================
    unsigned long factorial(unsigned int n);
    
    // ================================
    // Operations on two variables
    // ================================
    int gcd(int a, int b);
    int min(int a, int b); 
    int max(int a, int b);
    
    // ================================
    // Advanced math operations
    // ================================
    double arctan(double x);
    double arctan2(double y, double x);
    double sqrt(double n, int maxIterations = 3);   
    double ln(double x);
    double pow(double n, int rec);
    
    // ================================
    // Absolute value functions
    // ================================
    int abs(int x);
    double abs(double x);
    
    // ================================
    // Number property checks
    // ================================
    bool isPrime(int n);

    // ================================
    // Rounding functions
    // ================================
    double round(double x);
    double floor(double x);
    double ceil(double x);
    double trunc(double x);

    // ================================
    // Display and formatting
    // ================================
    std::string angle_string(double angle_rad, double tolerance = 1e-10);
}