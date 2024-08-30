struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* h;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val <= l2->val) {
        h = l1;
        struct ListNode* c = h;
        struct ListNode* cN = c->next;
        struct ListNode* o = l2;
        struct ListNode* oN = o->next;
        while (cN != NULL && o != NULL) {
            if (cN->val <= o->val) {
                c = cN;
                cN = cN->next;
            } else {
                c->next = o;
                o->next = cN;
                o = oN;
                if (o != NULL && o->next != NULL)
                    oN = o->next;
                else oN = NULL;
                c = c->next;
                cN = c->next;
            }
        }
        if (cN == NULL && o != NULL) {
            c->next = o;
        }
    } else {
        h = l2;
        struct ListNode* c = h;
        struct ListNode* cN = c->next;
        struct ListNode* o = l1;
        struct ListNode* oN = o->next;
        while (cN != NULL && o != NULL) {
            if (cN->val <= o->val) {
                c = cN;
                cN = cN->next;
            } else {
                c->next = o;
                o->next = cN;
                o = oN;
                if (o != NULL && o->next != NULL)
                    oN = o->next;
                else oN = NULL;
                c = c->next;
                cN = c->next;
            }
        }
        if (cN == NULL && o != NULL) {
            c->next = o;
        }
    }
    return h;
}
