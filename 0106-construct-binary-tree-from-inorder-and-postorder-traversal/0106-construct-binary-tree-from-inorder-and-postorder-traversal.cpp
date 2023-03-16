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
    int i;
    
    TreeNode* build(vector<int> &in, vector<int>& post, int l, int r)
    {
        if(l>r) return NULL;
        --i;
        TreeNode *root;
        for(int j = l; j<=r; ++j)
        {
            if(post[i] == in[j]) 
            {
                root = new TreeNode(in[j]);
                root->right = build(in, post, j+1, r);
                root->left = build(in, post, l, j-1);
                break;
            }
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        i = post.size();
        return build(in, post, 0, i-1);
    }
};