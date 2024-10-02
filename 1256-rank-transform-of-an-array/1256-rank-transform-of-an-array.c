#include <alloca.h>
#include <stdlib.h>

typedef struct {
	int val;
	int ind;
} IndexedValue;

int compare(const void *a, const void *b) {
	return ((IndexedValue *) a)->val - ((IndexedValue *) b)->val;
}

int* arrayRankTransform(int* arr, int n, int* returnSize) {
	IndexedValue *indexed = alloca(sizeof(IndexedValue) * n);

	for (int i = 0; i < n; ++i) {
		indexed[i] = (IndexedValue) {
			.val = arr[i],
			.ind = i
		};
	}

	qsort(indexed, n, sizeof(IndexedValue), compare);

	int *res = malloc(sizeof(int) * n);
    int sameRanks = 0;
	for (int i = 0; i < n; ++i) {
		IndexedValue a = indexed[i];
		res[a.ind] = i + 1 - sameRanks;
        if (i < n - 1 && indexed[i].val == indexed[i + 1].val)
            ++sameRanks;
	}

	*returnSize = n;
	return res;
}