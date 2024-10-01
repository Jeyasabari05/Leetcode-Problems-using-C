bool canArrange(int* arr, int arrSize, int k) {
    int ka[k];
    int i, t;
    i ^= i;
    while (i < k) {
        ka[i] = 0;
        ++i;
    }
    i ^= i;
    while (i < arrSize) {
        t = arr[i];
        t = ((t % k) + k) % k;
        ++ka[t];
        ++i;
    }

    if (ka[0] & 1)
        return 0;
    t = k >> 1;
    i = 1;
    while (i <= t) {
        if (ka[i] != ka[k - i])
            return 0;
        ++i;
    }
    return k & 1 || !(ka[t] & 1);
}