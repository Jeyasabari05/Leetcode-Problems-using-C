#define MAX_SIZE 100005

struct ListNode *modifiedList(int *a, int b, struct ListNode *c) {
    int d[MAX_SIZE] = {0};
    for (int i = 0; i < b; i++) {
        d[a[i]]++;
    }
    struct ListNode *e = (struct ListNode *)malloc(sizeof(struct ListNode));
    e->next = c;
    struct ListNode *f = e;
    struct ListNode *g = c;
    while (g != NULL) {
        if (d[g->val]) {
            f->next = g->next;
            free(g);
            g = f->next;
        } else {
            f = g;
            g = g->next;
        }
    }
    struct ListNode *h = e->next;
    free(e);
    return h;
}
