class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mn = INT_MAX;
        for(auto it: prices)
            ans = max(ans, it-mn), mn = min(mn, it);
        return ans;
    }
};