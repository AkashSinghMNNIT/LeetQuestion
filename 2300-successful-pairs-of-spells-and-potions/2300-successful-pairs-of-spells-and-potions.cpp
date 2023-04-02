class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        
        for(int i = 0; i<n; ++i)
        {
            int cnt;
            if(success%spells[i] == 0)
            cnt = m - (lower_bound(potions.begin(), potions.end(),(success/spells[i]))-potions.begin());
            else cnt = m -(lower_bound(potions.begin(), potions.end(),(success/spells[i] + 1))-potions.begin());
            ans.push_back(cnt);
        }
        return ans;
    }
};