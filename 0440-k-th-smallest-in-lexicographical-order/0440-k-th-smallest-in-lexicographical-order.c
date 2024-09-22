long long calcSteps(long long a, long long b) {
    long long c = 0;
    long long first = a;
    long long last = a + 1;
    while (first <= b) {
        c += (last <= b + 1) ? (last - first) : (b + 1 - first);
        first *= 10;
        last *= 10;
    }
    return c;
}
int findKthNumber(int b, int c) {
    int a = 1; 
    c -= 1;    
    while (c > 0) {
        long long steps = calcSteps(a, b);
        if (steps <= c) {
            c -= steps;
            a++;
        } else {
            a *= 10;
            c--;
        }
    }
    return a;
}
