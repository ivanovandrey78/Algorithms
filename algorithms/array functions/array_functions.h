#pragma once 
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <ctime>

void PrintMassive(int* a, int n);
double GetMiddleArray(int *a,int n);
int MinArray(int* a,int n);
int MaxArray(int* a,int n);
void ReverseArray(int* arr, int n);
int* GetUniqArray(int* arr,int n,int& res_size);
int* RandomMassive(int& n,int border);
int* InputArray(int& n);