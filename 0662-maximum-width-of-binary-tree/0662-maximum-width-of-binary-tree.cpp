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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            int start = q.front().second;
            int end = q.back().second;
            ans = max(ans, end-start+1);
            for(int i = 0; i<sz; ++i)
            {
                auto [node, id] = q.front();
                q.pop();
                long long idx = id-start;
                if(node->left) q.push({node->left, 2*idx + 1});
                if(node->right) q.push({node->right, 2*idx + 2});
            }   
        }
        return ans;
    }
};