int** construct2DArray(int* a, int b, int c, int d, int* e, int** f) {
    if (b != c * d) {
        *e = 0;
        return NULL;
    }
    *e = c;
    *f = (int*)malloc(sizeof(int) * c);
    int** g = (int**)malloc(sizeof(int*) * c);
    for (int i = 0; i < c; i++) {
        (*f)[i] = d;
        g[i] = &a[i * d];
    }
    return g;
}
