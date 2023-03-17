class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.length(), m = b.length();
        int dp[n+1][m+1];
        for(int i = 0; i<=n; ++i) dp[i][0] = 0;
        for(int i = 0; i<=m; ++i) dp[0][i] = 0;
        
        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1; j<=m; ++j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(a[i-1]==b[j-1]) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
};