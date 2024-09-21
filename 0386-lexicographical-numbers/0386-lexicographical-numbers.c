int* lexicalOrder(int n, int* returnSize) {
    int* retNum = (int*)malloc(n * sizeof(int));
    int v = 1;
    for (int i = 0; i < n; i++) {
        retNum[i] = v;
        if (v * 10 <= n) {
            v *= 10;
        } else {
            while (v % 10 == 9 || v == n) {
                v /= 10;
            }
            v++;
        }
    }
    *returnSize = n;
    return retNum;
}