struct ListNode* deleteDuplicates(struct ListNode* a) {
    if (a == NULL || a->next == NULL)
        return a;    
    struct ListNode* b = a;    
    while (b->next != NULL) {
        if (b->val == b->next->val) {
            struct ListNode* c = b->next;
            b->next = b->next->next;
            free(c);
        } else {
            b = b->next;
        }
    }    
    return a;
}
