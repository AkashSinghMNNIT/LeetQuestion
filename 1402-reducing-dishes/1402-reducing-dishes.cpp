class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int n = size(v), inf = 1e7;
        sort(begin(v), end(v));
        vector<vector<int>> dp(n+1, vector<int>(n+1, -inf));
        for(int i=0; i<=n; ++i) dp[i][0] = 0;
        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1; j<=i; ++j)
            {
                dp[i][j] = max(dp[i-1][j], v[i-1]*j + dp[i-1][j-1]);
            }
        }
        int ans = 0;
        for(int i = 0; i<=n; ++i) ans = max(ans, dp[n][i]);

        return ans;
    }
};