#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <cmath>
#include <cstdint> 

namespace mymath {
    double pow(double n,int rec);
    double SqrtNewton(double n);
    uint64_t Factorial(uint32_t n);
    int Min(int a,int b); int Max(int a,int b);
    double sqrt(int n);
}

void PrintMassive(int* a, int n);
double GetMiddleArray(int *a,int n);
int MinArray(int* a,int n);
int max_array(int* a,int n);
void ReverseArray(int* arr, int n);
int* GetUniqArray(int* arr,int n,int& res_size);
int* Merge(int* a,int n_a,int* b,int n_b,int& bg_size);
int StrLen(const char* string);
int SymbolIndex(char symbol,const char* s);
void Print(const char* s);
bool isPrime(int n);
int* RandomMassive(int& n,int border);
int* InputArray(int& n);
bool IsSorted(int* arr,int n);

#endif