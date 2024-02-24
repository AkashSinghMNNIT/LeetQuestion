/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if(root == NULL){
            return traversal;
        }
        my_stack.push(root);
        if(root->left != NULL){
            pre = root;
            current = root->left;
        }
        else if(root->right != NULL){
            pre = root;
            current = root->right;
        }
        else
        {
            my_stack.pop();
            traversal.push_back(root->val);
            return traversal;
        }
        while(!my_stack.empty()){
            if((current == pre->left) || (current == pre->right)){
                if(current->left != NULL){
                    my_stack.push(current);
                    pre = current;
                    current = current->left;
                }
                else if(current->right != NULL){
                    my_stack.push(current);
                    pre = current;
                    current = current->right;
                }
                else{
                    traversal.push_back(current->val);
                    pre = current;
                    current = my_stack.top();
                }
            }
            else if (pre == current->left){
				if (current->right != NULL){
					pre = current;
					current = current->right;
				}
				else{
					traversal.push_back(current->val);
					my_stack.pop();
					pre = current;
					if (!my_stack.empty()){
						current = my_stack.top();
					}					
				}
			}
			else if (pre == current->right){
				traversal.push_back(current->val);
				my_stack.pop();
				pre = current;
				if (!my_stack.empty()){
					current = my_stack.top();
				}
			}
            
        }
        return traversal;
    }
    
private:
    vector<int> traversal;
    stack<TreeNode*> my_stack;
    TreeNode *current;
    TreeNode *pre;
};