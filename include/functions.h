#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <cmath>
#include <cstdint> 

void PrintMassive(int* a, int n);
double GetMiddleArray(int *a,int n);
int MinArray(int* a,int n);
int max_array(int* a,int n);
void ReverseArray(int* arr, int n);
int* GetUniqArray(int* arr,int n,int& res_size);
int Min(int a,int b); int Max(int a,int b);
int* Merge(int* a,int n_a,int* b,int n_b,int& bg_size);
int StrLen(const char* string);
short int SymbolIndex(char symbol,std::string s);
void Print(std::string);
double Pow(double n,int rec);
double SqrtNewton(double n);
bool isPrime(int n);
int* RandomMassive(int& n,int border);
int* InputArray(int& n);
uint64_t Factorial(uint32_t n);

#endif