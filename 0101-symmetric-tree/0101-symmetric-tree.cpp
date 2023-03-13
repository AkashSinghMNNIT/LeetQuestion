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
public:vector<int> v1,v2;
    bool issame(TreeNode* p, TreeNode* q)
    {
        if(!p || !q) return p == q;
        else 
        {
            return (p->val == q->val) && (issame(p->left, q->right) && (issame(p->right, q->left)));
        }
    }
    bool isSymmetric(TreeNode* root) {
      
        if(!root) return true;
        return issame(root->left, root->right);
    }
};