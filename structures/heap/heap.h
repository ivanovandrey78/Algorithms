#pragma once
#include <iostream>
#include <stdexcept>

enum class HeapType {
    kMinHeap,
    kMaxHeap,
};

// Main heap functions
void SiftDown(int* arr, int size, int i, HeapType type);
void SiftUp(int* arr, int size, int i, HeapType type);
void BuildHeap(int* arr, int size, HeapType type);
bool IsHeap(int* arr, int size, HeapType type);
HeapType DetectHeapType(int* arr, int size);
void heapSort(int* arr, int size, HeapType type);

// Overloaded versions (auto-detect type)
void SiftDown(int* arr, int size, int i);
void SiftUp(int* arr, int size, int i);
void BuildHeap(int* arr, int size);
bool IsHeap(int* arr, int size);
void heapSort(int* arr, int size);

// Katalan number. (Heap to Bracket sequence)
std::string heapToPureBrackets(int* heap, int size, int index = 0);
std::string heapToBracketSequence(int* heap, int size, int index = 0);

// Priority Queue class
class PriorityQueue {
    private:
        // Data.
        int* data_;
        int capacity_;
        int size_;
        HeapType type_;

        void Resize(int new_capacity);
        void SiftUp(int i);
        void SiftDown(int i);

    public:
        // Constructors & destructor
        PriorityQueue(HeapType type = HeapType::kMaxHeap);
        PriorityQueue(int* arr, int arr_size, HeapType type = HeapType::kMaxHeap);
        ~PriorityQueue();
        
        // Copy constructor & assignment operator
        PriorityQueue(const PriorityQueue& other);
        PriorityQueue& operator=(const PriorityQueue& other);

        // Main operations
        void Push(int value);
        int Pop();
        int Top() const;
        
        // Utility functions
        bool Empty() const;
        int Size() const;
        int Capacity() const;
        void Clear();
        HeapType GetType() const;
        
        // Debug functions
        void Print() const;
        bool Validate() const;
};