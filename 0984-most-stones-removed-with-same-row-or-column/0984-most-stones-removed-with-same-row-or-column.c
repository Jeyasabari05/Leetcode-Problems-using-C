typedef struct {
    int* p;
    int* r;
} UF;
UF* newUF(int l) {
    UF* u = malloc(sizeof(UF));
    u->p = malloc(sizeof(int) * l);
    u->r = calloc(l, sizeof(int));
    for(int i = 0; i < l; i++) u->p[i] = i;
    return u;
}

int find(UF* u, int x) {
    if(u->p[x] != x) u->p[x] = find(u, u->p[x]);
    return u->p[x];
}

void unionSet(UF* u, int x, int y) {
    int rx = find(u, x), ry = find(u, y);
    if(rx != ry) {
        if(u->r[rx] < u->r[ry]) u->p[rx] = ry;
        else if(u->r[rx] > u->r[ry]) u->p[ry] = rx;
        else { u->p[rx] = ry; u->r[ry]++; }
    }
}

void freeUF(UF* u) {
    free(u->p); free(u->r); free(u);
}

int removeStones(int** s, int n, int* c) {
    UF* u = newUF(n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i][0] == s[j][0] || s[i][1] == s[j][1])
                unionSet(u, i, j);
        }
    }

    int* v = calloc(n, sizeof(int));
    int comp = 0;
    for(int i = 0; i < n; i++) {
        int root = find(u, i);
        if(!v[root]) { v[root] = 1; comp++; }
    }

    freeUF(u); free(v);
    return n - comp;
}
