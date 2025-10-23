#include "math_functions.h"

namespace math {

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
    if(a <= b) return a;
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

int abs(int x) {
    return (x > 0) ? x : -x;
}

double abs(double x) {
    return (x > 0.0) ? x : -x;
}

bool isPrime(int n) { 
    bool flag = true;
    for (int d = 2; d < sqrt(n); d++) {
        if (n%d == 0) flag = false;
    }
    return flag;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

double arctan(double x) {

    if (x < -1.0 || x > 1.0) {
        if (x > 1.0) {
            return PI_2 - arctan(1.0 / x);
        } else {
            return -PI_2 - arctan(1.0 / x);
        }
    }

    double result = 0.0;
    double x_pow = x;
    double x_squared = x * x;
    int sign = 1;

    for (int n = 0;n < 20; n++) { // max_iterations = 20
        double term = sign * x_pow / (2*n + 1);
        result += term;

        sign = -sign;
        x_pow *= x_squared;

        if (std::abs(term) < 1e-15) {
            break;
        }
    }
}

double arctg(double x, double y) {
    return x;
}

}