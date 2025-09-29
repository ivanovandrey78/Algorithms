#include "../include/functions.h"

void printMassive(int* a, int n) {
    std::cout << '{';
    for (int i=0;i<n;i++) {
        if (i == n-1)
        std::cout << a[i] << '}';
        else 
        std::cout << a[i] << ", ";
    }   
    std::cout << '\n';
} 

double get_sr(int *a,int n) {
    double sum = 0;
    for (int i=0;i<n;i++) sum += a[i];
    sum = sum/n;
    return sum;
}

int min_array(int* a,int n) {
    int m = get_sr(a,n);
    for(int i=0;i<n;i++) {
        if (m>a[i]) m = a[i];
    }
    return m;
}

int max_array(int *a,int n) { 
    int m = get_sr(a,n);
    for(int i=0;i<n;i++) {
        if (m<a[i]) m = a[i];
    }
    return m;
}

void revArray(int* arr, int n) {
   for (int i=0;i<n/2;i++) 
       std::swap(arr[i],arr[n-i-1]);
}

int min(int a,int b) {
    if(a<=b) return a;
    return b;
}

int max(int a,int b) { 
    if(a>=b) return a;
    else return b;
}

int strLength(std::string s) { 
    short int c = 0;
    for (auto x: s) { 
        c++; 
    }
    return c;
}

short int index(char symbol,std::string s) {
    for (int i=0;i<strLength(s);i++) {
        if (symbol == s[i]) 
            return i;
    }
    return -1;
}

void print(std::string s) {
    std::cout << s << ' ';
}

double pow(double n,int rec) {
    double prod = 1;
    for (int i=0;i<rec;i++)
        prod *= n;
    return prod;
}

double sqrtNewton(double n) { 
    if (n < 0.0) { std::cerr << "Error: Number must be positive. Error code: "; return -1;}
    else if (n == 0) return 0;


    double x = (n+1)/2;

    double x_before = 0;
    int c = 0;
    while (c != 100 && abs(x-x_before) != pow(0.1,6)) {
        x_before = x;
        x = x - ((pow(x,2)-n) / (2*x));
        c++;
    }

    return x;
}

bool isPrime(int n) { 
    bool flag = true;
    for (int d = 2; d < sqrtNewton(n); d++) {
        if (n%d == 0) flag = false;
    }
    return flag;
}

int* randomMassive(int& n,int border) {
    std::cin >> n;
    int* arr = new int[n];
    srand(time(0));
    for(int i = 0; i<n;i++) {
        arr[i] = rand()%border+1;
    }
    return arr; 
}

int* inputArray(int& n) {
    
    std::cin >> n;
    int* arr = new int[n];

    for(int i = 0; i<n; i++) 
    {
        std::cin >> arr[i];
    }

    return arr;

}