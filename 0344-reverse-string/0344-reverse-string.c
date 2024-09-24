void reverseString(char* s, int sSize) {
    int j = sSize - 1;
    int m = sSize >> 1;
    char temp;
    
    for (int i = 0; i < m; i++) {
        temp = s[i];
        s[i] = s[j];
        s[j--] = temp;
    }
}