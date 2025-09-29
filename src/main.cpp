#include "../include/functions.h"
#include "../include/sorts.h"
#include "../include/pyramid.hpp"

struct Track {
    int popularity;
    int stability; 
    int initialPosition;
};

bool compareTracks(const Track& t1, const Track& t2) {
    if (t1.popularity != t2.popularity)
        return t1.popularity < t2.popularity;  // popularity

    if (t1.stability != t2.stability)
        return t1.stability < t2.stability;    // stable

    return t1.initialPosition < t2.initialPosition; // init pos 
}

void mergeTracks(int* res,int*a,size_t sizeA,int*b,size_t sizeB) {
    
    int i=0,j=0;
    int indexNow = 0;
    
    while (i < sizeA && j < sizeB) {
        if (compareTracks()) {
            res[indexNow] = a[i];
            i++;
            indexNow++;
        }
        else {
            res[indexNow] = b[j];
            j++;
            indexNow++;
        }
    }
    while (i < sizeA) {
        res[indexNow] = a[i];
        indexNow++;
        i++;
    }
    while (j < sizeB) {
        res[indexNow] = b[j];
        indexNow++;
        j++;
    }
}

void mergeSortTracks(int* a,size_t sizeA) {

    if (sizeA <= 1) 
    {
        return;
    }

    size_t mid = sizeA/2;
    int* left = new int[mid];
    int* right = new int[sizeA-mid];

    for (size_t i=0;i<mid;i++) 
    {
        left[i] = a[i];
    }
    for (size_t i = mid;i<sizeA;i++) 
    {
        right[i-mid] = a[i];
    }

    mergeSort(left,mid);
    mergeSort(right,sizeA-mid);

    merge(a,left,mid,right,sizeA-mid);

    delete[] left;
    delete[] right;
}

int main() {

    int n; std::cin >> n; //init 
    Track chart[n];

    for (int i = 0; i < n; i++) //input
    {
        std::cin >> chart[i].popularity;
        std::cin >> chart[i].stability;
        chart[i].initialPosition = i+1;
    }



    return 0;
}