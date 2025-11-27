#pragma once 

#include <cstdlib>
#include <cstring>
#include <iostream>

enum class DataType { 
  kInt, 
  kIntArray, 
  kFloat, 
  kFloatArray, 
  kString, 
  kStringArray
};

class Value {
private:
  DataType type;
  bool is_repeat;
    
  union {
    // simple type - one value
    int int_val;
    float float_val;
    char* str_val;
    
    // arrays
    struct {
        int* data;
        size_t size;
    } int_array;
    
    struct {
        float* data;
        size_t size;
    } float_array;
    
    struct {
        char** data;
        size_t size;
    } string_array;
      
  } data;
    
public:
  // constructor for simple value
  Value(int val) : type(DataType::kInt), is_repeat(false) { data.int_val = val; }

  Value(float val) : type(DataType::kFloat), is_repeat(false) { data.float_val = val; }
  
  Value(const char* val) : type(DataType::kString), is_repeat(false) {
      if (val) {
          data.str_val = new char[strlen(val) + 1];
          strcpy(data.str_val, val);
      } else {
          data.str_val = nullptr;
      }
  }
    
  // constructors for arrays
  Value(const int* arr, size_t size = 16) : type(DataType::kIntArray), is_repeat(false) {
      data.int_array.data = new int[size];
      data.int_array.size = size;
      memcpy(data.int_array.data, arr, size * sizeof(int));
  }
  
  Value(const float* arr, size_t size = 16) : type(DataType::kFloatArray), is_repeat(false) {
      data.float_array.data = new float[size];
      data.float_array.size = size;
      memcpy(data.float_array.data, arr, size * sizeof(float));
  }
  
  Value(const char** arr, size_t size) : type(DataType::kStringArray), is_repeat(false) {
      data.string_array.data = new char*[size];
      data.string_array.size = size;
      for (size_t i = 0; i < size; ++i) {
          data.string_array.data[i] = new char[strlen(arr[i]) + 1];
          strcpy(data.string_array.data[i], arr[i]);
      }
  }
  
  // destructor
  ~Value() { cleanup(); }
  
  void cleanup() {
    switch (type) {
      case DataType::kString:
          if (data.str_val) {
              delete[] data.str_val;
              data.str_val = nullptr;
          }
          break;
      case DataType::kIntArray:
          if (data.int_array.data) {
              delete[] data.int_array.data;
              data.int_array.data = nullptr;
          }
          break;
      case DataType::kFloatArray:
        if (data.float_array.data) {
            delete[] data.float_array.data;
            data.float_array.data = nullptr;
        }
        break;
      case DataType::kStringArray:
        if (data.string_array.data) {
            for (size_t i = 0; i < data.string_array.size; ++i) {
                delete[] data.string_array.data[i];
            }
            delete[] data.string_array.data;
            data.string_array.data = nullptr;
        }
          break;
          
      default: break;
    }
  }
    
    // copying constructor
    Value(const Value& other) : type(other.type), is_repeat(other.is_repeat) { copyFrom(other); }
    
  // assignment operator
  Value& operator=(const Value& other) {
    if (this != &other) {
      cleanup();
      type = other.type;
      is_repeat = other.is_repeat;
      copyFrom(other);
    }
    return *this;
  }
    
private:
  void copyFrom(const Value& other) {
    switch (type) {
      case DataType::kInt:   data.int_val = other.data.int_val;     break;
      case DataType::kFloat: data.float_val = other.data.float_val; break;

      case DataType::kString: {
        if (other.data.str_val) {
          data.str_val = new char[strlen(other.data.str_val) + 1];
          strcpy(data.str_val, other.data.str_val);
        }
        break;
      }

      case DataType::kIntArray: {
        data.int_array.data = new int[other.data.int_array.size];
        data.int_array.size = other.data.int_array.size;
        memcpy(data.int_array.data, other.data.int_array.data, 
        other.data.int_array.size * sizeof(int));
        break;
      }

      case DataType::kFloatArray: {
        data.float_array.data = new float[other.data.float_array.size];
        data.float_array.size = other.data.float_array.size;
        memcpy(data.float_array.data, other.data.float_array.data,
        other.data.float_array.size * sizeof(float));
        break;
      }

      case DataType::kStringArray: {
        data.string_array.data = new char*[other.data.string_array.size];
        data.string_array.size = other.data.string_array.size;
        for (size_t i = 0; i < data.string_array.size; ++i) {
          data.string_array.data[i] = new char[strlen(other.data.string_array.data[i]) + 1];
          strcpy(data.string_array.data[i], other.data.string_array.data[i]);
        }
        break;
      }
    }
  }
};

class List {
private:
  Value* data;
  size_t count;
  size_t capacity;

public:
  // constructors
  List();
  List(size_t initial_capacity);
  List(List&& other) noexcept;
  List(const List& other);

  List& operator=(const List& other);  // copy assignment
  List& operator=(List&& other) noexcept;  // move assignment

  // destructor
  ~List();

  // main interface
  void append(int* value);
  void append(float* value);
  void append(const char* value);
  void remove(size_t index);
  
  // get Value data
  Value& operator[](size_t index);
  const Value& operator[](size_t index) const;

  // getters 
  size_t size() const { return count; }
  size_t get_capacity() const { return capacity; }
  bool empty() const { return count == 0; }

  // iterators 
  Value* begin() { return data; }
  Value* end() { return data + count; }
  const Value* begin() const { return data; }
  const Value* end() const { return data + count; }

  // memory management
  bool resize(size_t new_capacity);
  bool reserve(size_t capacity); 
  void shrink_to_fit();
};