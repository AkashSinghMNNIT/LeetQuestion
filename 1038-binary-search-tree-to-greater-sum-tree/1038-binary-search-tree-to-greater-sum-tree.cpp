/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void transform(TreeNode* root, int &sum)
    {
        if(root == NULL) return;
        transform(root->right, sum);
        sum += root->val;
        root->val = sum;
        transform(root->left, sum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        transform(root, sum);
        return root;
    }
};