#define ll long long
class Solution {
public:
    long long maximumTotalCost(vector<int>& v) {
        int n = v.size(), ans =0;
        vector<ll> dp(n+1, 0);
        for(int i=1; i<=n; ++i)
        {
            dp[i] = dp[i-1]+ v[i-1];
            if(i>1) dp[i] = max(dp[i], dp[i-2]+v[i-2]-v[i-1]);
        }
        return dp[n];
    }
};