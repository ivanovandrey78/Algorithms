# Pyramid Library

Универсальная C++ библиотека для работы с бинарными кучами. Поддерживает min-heap и max-heap с автоматическим определением типа.

## Функции

### Основные операции

- **`SiftDown(int* arr, int size, int i, HeapType type)`** - Просеивание вниз (O(log n))
- **`SiftUp(int* arr, int size, int i, HeapType type)`** - Просеивание вверх (O(log n))  
- **`BuildHeap(int* arr, int size, HeapType type)`** - Построение кучи (O(n))
- **`IsHeap(int* arr, int size, HeapType type)`** - Проверка свойств кучи (O(n))
- **`heapSort(int* arr, int size, HeapType type)`** - Пирамидальная сортировка (O(n log n))

### Перегруженные версии (автоопределение типа)

- **`SiftDown(int* arr, int size, int i)`**
- **`SiftUp(int* arr, int size, int i)`**
- **`BuildHeap(int* arr, int size)`**
- **`IsHeap(int* arr, int size)`**
- **`heapSort(int* arr, int size)`**

### Вспомогательные функции

- **`DetectHeapType(int* arr, int size)`** - Определение типа кучи (O(n))
- **`HeapType`** - Перечисление: `kMinHeap`, `kMaxHeap`

## Примеры использования

```cpp
#include "pyramid.h"

int main() {
    int arr[] = {5, 3, 8, 1, 2};
    int size = 5;
    
    // Явное указание типа
    BuildHeap(arr, size, HeapType::kMaxHeap);
    heapSort(arr, size, HeapType::kMaxHeap);
    
    // Автоопределение типа (работает как перегрузка)
    BuildHeap(arr, size);
    heapSort(arr, size);
    
    return 0;
}
```

> **P.S.** По умолчанию все функции заточены под MinHeap (смотрите в pyramid.h). Если хотите изменить тип, просто укажите его в функции последним аргументом (инфа также в хедере)