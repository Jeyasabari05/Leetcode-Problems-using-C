#include <string.h>
#include <math.h>

int memo[51][51];

int findMaxLen(char *a, char **b, int c, int d, int e, int f) {
    if (c == f)
        return 0;
    if (memo[c][d] != -1)
        return memo[c][d];

    if (d == e) {
        memo[c][d] = findMaxLen(a, b, c + 1, 0, e, f);
        return memo[c][d];
    }

    int g = strlen(b[d]);
    if (strncmp(&(a[c]), b[d], g) == 0) {
        int path1 = g + findMaxLen(a, b, c + g, 0, e, f);
        int path2 = findMaxLen(a, b, c, d + 1, e, f);
        memo[c][d] = fmax(path1, path2);
        return memo[c][d];
    } else {
        return findMaxLen(a, b, c, d + 1, e, f);
    }
}

int minExtraChar(char *a, char **b, int c) {
    memset(memo, -1, sizeof(memo));
    return strlen(a) - findMaxLen(a, b, 0, 0, c, strlen(a));
}
