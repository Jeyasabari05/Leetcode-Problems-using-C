#include <stdbool.h>
#include <string.h>
bool isAnagram(char* s, char* t) {
    int size = strlen(s);
    if (size != strlen(t)) {
        return false;
    }
    int freqArr[26] = {0}; 
    for (int i = 0; i < size; i++) {
        freqArr[(int)s[i] - 97]++;
    }
    for (int i = 0; i < size; i++) {
        freqArr[(int)t[i] - 97]--;
    }
    for (int i = 0; i < 26; i++) {
        if (freqArr[i] != 0) {
            return false;
        }
    }
    return true;
}