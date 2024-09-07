#include <stdbool.h> 
#include <stdlib.h> 
bool dfs(struct ListNode* head, struct TreeNode* root) {
    if (!head) return true;   
    if (!root) return false;   
    if (head->val != root->val) return false; 
    return dfs(head->next, root->left) || dfs(head->next, root->right);
}
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (!root) return false; 
    struct ListNode* a;    
    struct TreeNode* b;    
    bool c;                
    a = head;
    b = root;
    c = false;
    if (dfs(a, b)) {
        c = true;
    } else {
        c = isSubPath(a, b->left) || isSubPath(a, b->right);
    }
    return c;
}
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct ListNode* newListNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
