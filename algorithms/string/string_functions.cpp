#include "string_functions.h"

int StrLen(const char* string) {
    int c = 0;
    while (*string++) c++;
    c--;
    return c;
}

int SymbolIndex(char symbol,const char* s) {
    for (int i=0;i<StrLen(s);i++) {
        if (symbol == s[i]) 
            return i;
    }
    return -1;
}

void Print(const char* s) { std::cout << s << '\n'; }

const char* StrFind(const char* str, const char* substr) {
    int sub_len = StrLen(substr);
    if (sub_len == 0) return str;

    for (int i = 0; str[i] != '\0'; i++) {
    bool found = true;
    for (int j = 0; j < sub_len; j++) {
        if (str[i + j] != substr[j]) {
            found = false;
            break;
        }
    }
    if (found) return &str[i];
    }
    return nullptr;
}

bool IsEqual(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return false;
            i++;
        }
    return str1[i] == '\0' && str2[i] == '\0';
}

char* StrCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* StrCopyN(char* dest, const char* src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

const char* SkipSpaces(const char* str) {
    while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n') {
        str++;
    }
    return str;
}
    
void TrimRight(char* str) {
    int len = StrLen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || 
                        str[len - 1] == '\n' || str[len - 1] == '\r')) {
    str[len - 1] = '\0';
    len--;
    }
}