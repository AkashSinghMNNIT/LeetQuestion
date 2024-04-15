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
    
    void dfs(TreeNode* root, int &ans, int curr)
    {
        if(root->left == NULL && root->right == NULL) ans += curr*10 + root->val;
        else
        {
            if(root->left) dfs(root->left, ans, curr*10 + root->val);
            if(root->right) dfs(root->right, ans, curr*10 + root->val);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
};