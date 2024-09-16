int convert(char* s) {
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[3] - '0') * 10 + (s[4] - '0');
    return a * 60 + b;
}

int cmp(const void *p1, const void *p2) {
    int a = *(int*)p1;
    int b = *(int*)p2;
    return (a < b) ? -1 : 1;
}

int findMinDifference(char** t, int n) {
    int c[n];
    for (int i = 0; i < n; i++) {
        c[i] = convert(t[i]);
    }
    qsort(c, n, sizeof(int), cmp);
    
    int minDiff = 24 * 60 - c[n - 1] + c[0];
    for (int i = 1; i < n; i++) {
        int diff = c[i] - c[i - 1];
        if (minDiff > diff) minDiff = diff;
    }
    
    if (minDiff > 24 * 60 - minDiff) minDiff = 24 * 60 - minDiff;
    
    return minDiff;
}
