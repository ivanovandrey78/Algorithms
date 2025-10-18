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
    unsigned long Factorial(unsigned int n);
    int min(int a,int b); 
    int max(int a,int b);
    double sqrt(double n,int maxIterations = 3);
}

// array Functions
void PrintMassive(int* a, int n);
double GetMiddleArray(int *a,int n);
int MinArray(int* a,int n);
int MaxArray(int* a,int n);
void ReverseArray(int* arr, int n);
int* GetUniqArray(int* arr,int n,int& res_size);
bool isPrime(int n);
int* RandomMassive(int& n,int border);
int* InputArray(int& n);

// string functions
int StrLen(const char* string);
int SymbolIndex(char symbol,const char* s);
void Print(const char* s);

#endif