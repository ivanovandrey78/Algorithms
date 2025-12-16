#include <iostream>

const long long Mod = 1LL << 30;

struct Node {
    long long value;
    Node* prev;
    Node* next;
    
    Node(long long val) : value(val), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* front_;
    Node* back_;
    size_t size_;

public:
    Deque() : front_(nullptr), back_(nullptr), size_(0) {}
    ~Deque() { while (!IsEmpty()) PopFront(); }
    
    size_t GetSize() const { return size_; }
    long long GetFront() const { return IsEmpty() ? 0 : front_->value; }
    long long GetBack() const { return IsEmpty() ? 0 : back_->value; }
    
    void PushBack(long long value) {
        Node* node = new Node(value);
        if (IsEmpty()) {
            front_ = back_ = node;
        } else {
            back_->next = node;
            node->prev = back_;
            back_ = node;
        }
        ++size_;
    }
    
    void PushFront(long long value) {
        Node* node = new Node(value);
        if (IsEmpty()) {
            front_ = back_ = node;
        } else {
            node->next = front_;
            front_->prev = node;
            front_ = node;
        }
        ++size_;
    }
    
    long long PopFront() {
        if (IsEmpty()) return 0;
        Node* temp = front_;
        long long value = temp->value;
        front_ = front_->next;
        if (front_) front_->prev = nullptr;
        else back_ = nullptr;
        delete temp;
        --size_;
        return value;
    }
    
    long long PopBack() {
        if (IsEmpty()) return 0;
        Node* temp = back_;
        long long value = temp->value;
        back_ = back_->prev;
        if (back_) back_->next = nullptr;
        else front_ = nullptr;
        delete temp;
        --size_;
        return value;
    }
    
    bool IsEmpty() const { return size_ == 0; }

    void Print() const {
        Node* current = front_;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};