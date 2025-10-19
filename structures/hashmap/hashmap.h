#pragma once
#define TABLE_SIZE 1024
#define CSTRING_SIZE 100

#include "../algorithms/string/string_functions.h"

enum class CellState {
    kCellEmpty,
    kCellReserved, 
    kCellDeleted,
};

struct Cell {
    char key[CSTRING_SIZE];
    char value[CSTRING_SIZE];
    CellState state;
};

struct HashMap {
    Cell map_cells[TABLE_SIZE];
    int size;
    int capacity;
};

// Hash map functions.
unsigned long HashFunction(const char* string); 
bool InsertMap(HashMap* map, const char* key, const char* value);
int FindIndex(HashMap* map, const char* key);
void MapInit(HashMap* map);
bool HashmapFind(HashMap* map, const char* key, char* out_value);