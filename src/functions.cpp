#include "../include/functions.h"

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

int max_array(int *a,int n) { 
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

int Min(int a,int b) {
    if(a<=b) return a;
    return b;
}

int Max(int a,int b) { 
    if(a>=b) return a;
    else return b;
}

int StrLen(const char* string) {
    int c = 0;
    while (*string++) c++;
    c--;
    return c;
}

short int SymbolIndex(char symbol,const char* s) {
    for (int i=0;i<StrLen(s);i++) {
        if (symbol == s[i]) 
            return i;
    }
    return -1;
}

void Print(std::string s) {
    std::cout << s << ' ';
}

double Pow(double n,int rec) {
    double prod = 1;
    for (int i=0;i<rec;i++)
        prod *= n;
    return prod;
}

double SqrtNewton(double n) { 
    if (n < 0.0) { std::cerr << "Error: Number must be positive. Error code: "; return -1;}
    else if (n == 0) return 0;


    double x = (n+1)/2;

    double x_before = 0;
    int c = 0;
    while (c != 100 && abs(x-x_before) != Pow(0.1,6)) {
        x_before = x;
        x = x - ((Pow(x,2)-n) / (2*x));
        c++;
    }

    return x;
}

bool isPrime(int n) { 
    bool flag = true;
    for (int d = 2; d < SqrtNewton(n); d++) {
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

    for(int i = 0; i<n; i++) 
    {
        std::cin >> arr[i];
    }

    return arr;

}

int SumArray(int *a, int n) {
    int c = 0;
    for(int i = 0;i<n;i++) c+=a[i];
    return c;
}

uint64_t Factorial(uint32_t n) {
    uint64_t result;

    if (n==0) {
        result = 1;
    } else {
        result = n * Factorial(n-1);
    }

    return result;
}