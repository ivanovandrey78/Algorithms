#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <cmath>

void print_massive(int* a, int n);
double get_sr(int *a,int n);
int min_array(int* a,int n);
int max_array(int* a,int n);
int get_rev_arr(int* arr, int n);
int* get_uniq(int* arr,int n,int& res_size);
int min(int a,int b); int max(int a,int b);
int* get_merge_array(int* a,int n_a,int* b,int n_b,int& bg_size);
int strLength(std::string s);
short int index(char symbol,std::string s);
void print(std::string);
double pow(double n,int rec);
double sqrtNewton(double n);
bool isPrime(int n);
int* randomMassive(int& n,int border);
int* inputArray(int& n);

#endif