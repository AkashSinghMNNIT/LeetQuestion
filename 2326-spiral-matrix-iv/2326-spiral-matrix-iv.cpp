/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int> (n, -1));
        int i =0, j =0;
        while(head!=NULL)
        {
            if(j<n)
            {
                while(j<n && head!=NULL && (mat[i][j]==-1))
                {
                    mat[i][j] = head->val;
                    head = head->next;
                    ++j;
                }
                if(head == NULL) break;
                --j;
                ++i;
            }
            if(i<m)
            {
                while(i<m && head!=NULL && (mat[i][j]==-1))
                {
                    mat[i][j] = head->val;
                    head = head->next;
                    ++i;
                }
                if(head == NULL) break;
                --i;
                --j;
            }
            if(j>=0)
            {
                while(j>=0 && head!=NULL && (mat[i][j]==-1))
                {
                    mat[i][j] = head->val;
                    head = head->next;
                    --j;
                }
                if(head == NULL) break;
                ++j;
                --i;
            }
            if(i>=0)
            {
                while(i>=0 && head!=NULL && (mat[i][j]==-1))
                {
                    mat[i][j] = head->val;
                    head = head->next;
                    --i;
                }
                if(head == NULL) break;
                ++i;
                ++j;
            }
            --m;
            --n;
        }
        return mat;
    }
};