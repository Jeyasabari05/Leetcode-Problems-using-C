#include <stdio.h>
#include <stdlib.h>

int cmp(const void* x, const void* y) {
    return (*(int*)x - *(int*)y);
}

void backtrack(int* a, int aSize, int t, int** res, int* rCount, int* colSizes, int* temp, int tempSize, int start) {
    if (t == 0) {
        res[*rCount] = (int*)malloc(tempSize * sizeof(int));
        for (int i = 0; i < tempSize; i++) {
            res[*rCount][i] = temp[i];
        }
        colSizes[*rCount] = tempSize;
        (*rCount)++;
        return;
    }
    for (int i = start; i < aSize; i++) {
        if (i > start && a[i] == a[i - 1]) continue;
        if (a[i] > t) break;
        temp[tempSize] = a[i];
        backtrack(a, aSize, t - a[i], res, rCount, colSizes, temp, tempSize + 1, i + 1);
    }
}

int** combinationSum2(int* a, int aSize, int t, int* rSize, int** colSizes) {
    qsort(a, aSize, sizeof(int), cmp);
    int** res = (int**)malloc(sizeof(int*) * 1000);
    *colSizes = (int*)malloc(sizeof(int) * 1000);
    int* temp = (int*)malloc(sizeof(int) * aSize);
    int rCount = 0;
    backtrack(a, aSize, t, res, &rCount, *colSizes, temp, 0, 0);
    free(temp);
    *rSize = rCount;
    return res;
}
