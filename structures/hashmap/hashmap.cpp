#include "hashmap.h"

// Creates index for hash table cell using djb2 algorithm.
unsigned long HashFunction(const char* string) {
    unsigned long hash = 5381;
    int c;

    while (true) {
    c = *string;
    string++;

    if (c == 0) break;
    hash = ((hash << 5) + hash) ^ c;
    }
    hash = hash % TABLE_SIZE;
    return hash;
}

// Finds index for key in hash map, used for cell insertion.
int FindIndex(HashMap* map, const char* key) {
    unsigned long index = HashFunction(key);
    unsigned long start_index = index;
    int first_deleted = -1;

    while (map->map_cells[index].state != CellState::kCellEmpty) {
    if (map->map_cells[index].state == CellState::kCellReserved && 
        IsEqual(map->map_cells[index].key, key)) {
        return index;
    }

    if (map->map_cells[index].state == CellState::kCellDeleted && first_deleted == -1) {
        first_deleted = index;
    }

    index = (index + 1) % TABLE_SIZE;
    if (index == start_index) break;
    }

    return (first_deleted != -1) ? first_deleted : index;
}

bool InsertMap(HashMap* map, const char* key, const char* value) {
    if (map->size >= TABLE_SIZE) {
    return false;
    }

    if (StrLen(key) == 0 || StrLen(value) == 0) {
    return false;
    }

    if (StrLen(value) >= CSTRING_SIZE || StrLen(key) >= CSTRING_SIZE) {
    return false;
    }

    int index = FindIndex(map, key);

    if (map->map_cells[index].state == CellState::kCellReserved && 
        IsEqual(map->map_cells[index].key, key)) {
    StrCopy(map->map_cells[index].value, value);
    return true;
    }

    StrCopy(map->map_cells[index].key, key);
    StrCopy(map->map_cells[index].value, value);
    map->map_cells[index].state = CellState::kCellReserved;
    map->size++;

    return true;
}

void MapInit(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
    map->map_cells[i].state = CellState::kCellEmpty;
    map->map_cells[i].key[0] = '\0';
    map->map_cells[i].value[0] = '\0';
    } 
    map->size = 0;
    map->capacity = TABLE_SIZE;
}

bool HashmapFind(HashMap* map, const char* key, char* out_value) {
    int index = FindIndex(map, key);

    if (index != -1 && 
        map->map_cells[index].state == CellState::kCellReserved && 
        IsEqual(map->map_cells[index].key, key)) {
    StrCopy(out_value, map->map_cells[index].value);
    return true;
    }

    return false;
}