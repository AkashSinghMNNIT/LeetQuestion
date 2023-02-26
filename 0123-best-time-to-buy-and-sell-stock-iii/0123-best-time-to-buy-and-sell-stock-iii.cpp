#define ll long long
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        ll mn = INT_MAX, mx = INT_MIN, ans = 0, pre = 0;
        vector<ll> dp(n, 0);
        for(int i = 0; i<n; ++i) 
        {
            if(i) dp[i] = dp[i-1];
            dp[i] = max(dp[i], prices[i]-mn);
            mn = min(mn, 0ll + prices[i]);
        }
        for(int i = n-1; i>=0; --i)
        {
            pre = max(pre, mx-prices[i]);
            if(i)
            ans = max(ans, pre + dp[i-1]);
            mx = max(mx,0ll + prices[i]);
        }
        ans = max(ans, dp[n-1]);
        return ans;
    }
};