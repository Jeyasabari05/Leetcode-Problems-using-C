int cmp(char* p, char* s, int idx, int m){
    for (int i = 0; i < m; i++)
        if (p[i] != s[idx + i])
            return 0;
    return 1;
}
int strStr(char * haystack, char * needle){
    int M = 1e9 + 9, p = 31, n = strlen(haystack), m = strlen(needle);
    ssize_t h = 1, a = 0, b = 0;
    if (m > n) return -1;
    for (int i = 0; i < m - 1; i++){
        h = (h * p) % M;
    }
    for (int i = 0; i < m; i++){
        a = a * p + haystack[i];
        b = b * p + needle[i];
        a %= M;
        b %= M;
    }
    for (int i = m; i <= n; i++){
        if (a == b && cmp(needle, haystack, i - m, m)) return i - m;
        if (i < n) a = (p * (a - h * haystack[i - m]) + haystack[i]) % M;
        if (a < 0) a += M;
    }
    return -1;
}