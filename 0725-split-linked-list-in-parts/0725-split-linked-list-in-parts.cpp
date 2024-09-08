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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto cur = head;
        while(cur) {
            ++n; cur = cur->next;
        }
        vector<ListNode*> ans;

        ListNode* prev = nullptr;
        cur = head;
        int r = n-(k*(n/k));
        for(int i=0; i<k; i++) {
            int s = i<r? (1+n/k) : (n/k);
            ans.push_back(cur);
            for(int j=0; j<s; j++) {
                prev = cur;
                cur = cur->next;
            }
            if(prev) prev->next = nullptr;
        }

        return ans;
    }
};