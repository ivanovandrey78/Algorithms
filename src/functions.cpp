#include "../include/functions.h"

namespace mymath {

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

    double pow(double n,int rec) {
    double prod = 1;
    for (int i = 0;i < rec;i++) {prod *= n;}
    return prod;
    }

    unsigned long Factorial(unsigned int n) {
    unsigned long result;
    if (n==0) {
        result = 1;
    } else {
        result = n * Factorial(n-1);
    }
    return result;
    }
}

void PrintMassive(int* a, int n) {
    std::cout << '{';
    for (int i=0;i<n;i++) {
        if (i == n-1)
        std::cout << a[i] << '}';
        else 
        std::cout << a[i] << ", ";
    }   
    std::cout << '\n';
} 

double GetMiddleArray(int *a,int n) {
    double sum = 0;
    for (int i=0;i<n;i++) sum += a[i];
    sum = sum/n;
    return sum;
}

int MinArray(int* a,int n) {
    int m = GetMiddleArray(a,n);
    for(int i=0;i<n;i++) {
        if (m>a[i]) m = a[i];
    }
    return m;
}

int MaxArray(int *a,int n) { 
    int m = GetMiddleArray(a,n);
    for(int i=0;i<n;i++) {
        if (m<a[i]) m = a[i];
    }
    return m;
}

void ReverseArray(int* arr, int n) {
   for (int i=0;i<n/2;i++) 
       std::swap(arr[i],arr[n-i-1]);
}

int StrLen(const char* string) {
    int c = 0;
    while (*string++) c++;
    c--;
    return c;
}

int SymbolIndex(char symbol,const char* s) {
    for (int i=0;i<StrLen(s);i++) {
        if (symbol == s[i]) 
            return i;
    }
    return -1;
}

void Print(const char* s) { std::cout << s << '\n'; }

bool isPrime(int n) { 
    bool flag = true;
    for (int d = 2; d < mymath::sqrt(n); d++) {
        if (n%d == 0) flag = false;
    }
    return flag;
}

int* RandomMassive(int& n,int border) {
    std::cin >> n;
    int* arr = new int[n];
    srand(time(0));
    for(int i = 0; i<n;i++) {
        arr[i] = rand()%border+1;
    }
    return arr; 
}

int* InputArray(int& n) {
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) { std::cin >> arr[i]; }
    return arr;
}

int SumArray(int *a, int n) {
    int c = 0;
    for(int i = 0;i < n;i++) c += a[i];
    return c;
}