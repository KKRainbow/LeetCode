/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* vec;
int size = 0;
int cap = 0;
void push_back(int val) {
    if (size + 1 > cap) {
        cap = (cap + 1) * 2;
    }
    int *newvec = (int*)malloc(sizeof(int) * cap);
    memcpy(newvec, vec, sizeof(int) * size);
    newvec[size++] = val;
    free(vec);
    vec = newvec;
}

void traverse(struct TreeNode* node) {
    if (!node) return;
    traverse(node->left);
    push_back(node->val);
    traverse(node->right);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    vec = size = cap = 0;
    traverse(root);
    *returnSize = size;
    return vec;
}