#include "math_functions.h"

namespace mymath {

    constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944;
    constexpr double E = 2.718281828459045235360287471352662497757247093699959574966967;
    constexpr double LN2 = 0.693147180559945309417232121458176568075500134360255254120680;

    double sqrt(double n,int maxIterations) {
    if (n < 0) { std::cerr << "Number must be positive" << '\n'; return 1; }
    if (n == 1) return 1.0;
    if (n == 0) return 0.0;
    
    if (maxIterations <= 0) {
        int d = 1;
        while (d*d <= n) {
            if (d * d == n) return static_cast<double>(d);
            d++;
        }
        d--;
        double derivative = 1.0/(2.0*d);
        return d + (n - d*d)*derivative;
    }

    double currentApprox = sqrt(n, maxIterations-1);
    
    double derivative = 1.0/(2.0*currentApprox);
    double result = currentApprox + (n - currentApprox*currentApprox)*derivative;
    
    return result;
    }

    int min(int a,int b) {
    if(a<=b) return a;
    return b;
    }

    int max(int a,int b) { 
        if(a>=b) return a;
        else return b;
    }

    double pow (double n,int rec) {
    double prod = 1;
    for (int i = 0;i < rec;i++) {prod *= n;}
    return prod;
    }

    unsigned long factorial(unsigned int n) {
    unsigned long result;
    if (n==0) {
        result = 1;
    } else {
        result = n * factorial(n-1);
    }
    return result;
    }

    double ln(double x) {
        if (x <= 0) { 
            throw "ln(x) undefined for x <= 0"; 
        }
        
        int m = 0;
        double s = x;
        
        while (s >= 2.0) {
            s /= 2.0;
            m++;
        }
        while (s < 1.0) {
            s *= 2.0;
            m--;
        }
    
        double t = (s - 1.0) / (s + 1.0);
        double t_sq = t * t;
        double term = t;
        double sum = term;
        
        for (int k = 1; k <= 20; ++k) {
            term *= t_sq;
            double new_term = term / (2*k + 1);
            sum += new_term;
            
            if (new_term < 1e-16) break;
        }
        
        return 2.0 * sum + m * LN2;
    }

    bool isPrime(int n) { 
        bool flag = true;
        for (int d = 2; d < sqrt(n); d++) {
            if (n%d == 0) flag = false;
        }
        return flag;
    }
}