struct w {
    char a[256], b[256];
    UT_hash_handle hh;
};
int cmp(const void *x, const void *y) {
    return (*(char *)x - *(char *)y);
}
char *sortStr(char *s) {
    char *r = malloc(strlen(s) + 1);
    strcpy(r, s);
    qsort(r, strlen(r), 1, cmp);
    return r;
}
int wcmp(struct w *x, struct w *y) {
    return strcmp(x->a, y->a);
}
char ***groupAnagrams(char **strs, int n, int *rSize, int **cSizes) {
    struct w *x, *t, *h = NULL;
    char ***res = malloc(n * sizeof(char *));
    int *cs = malloc(n * sizeof(int)), i;
    *cSizes = cs;
    *rSize = -1;
    for (i = 0; i < n; i++) {
        char *sorted = sortStr(strs[i]);
        x = malloc(sizeof *x);
        strcpy(x->a, sorted);
        strcpy(x->b, strs[i]);
        HASH_ADD_STR(h, a, x);
        free(sorted);
    }
    HASH_SORT(h, wcmp);
    char *ana = NULL;
    HASH_ITER(hh, h, x, t) {
        if (ana && strcmp(x->a, ana) == 0) {
            res[*rSize][cs[*rSize]++] = x->b;
        } else {
            res[++*rSize] = malloc(n * sizeof(char *));
            cs[*rSize] = 0;
            res[*rSize][cs[*rSize]++] = x->b;
            ana = x->a;
        }
    }
    *rSize += 1;
    return res;
}
