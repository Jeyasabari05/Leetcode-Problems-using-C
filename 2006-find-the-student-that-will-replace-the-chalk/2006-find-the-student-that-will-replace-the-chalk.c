int chalkReplacer(int* c, int s, int k) {
    long sum = 0;
    int i = 0;
    for(; i < s; i++) {
        if(c[i] <= k) {
            k -= c[i];
            sum += c[i];
        } else return i;
    }
    long m = k / sum;
    k -= m * sum;
    if(k == 0) return 0;

    i = 0;
    for(; i < s; i++) {
        if(c[i] <= k) k -= c[i];
        else break;
    }
    return i;
}
