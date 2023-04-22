int dp[501][501];
class Solution {
public:
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        string t = s;
        reverse(begin(t), end(t));
        for(int i = 0; i<=n; ++i) dp[0][i] = dp[i][0] = 0;
        
        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1; j<=n; ++j)
            {
                dp[i][j] = (s[i-1]==t[j-1]?1+dp[i-1][j-1]:max(dp[i][j-1], dp[i-1][j]));
            }
        }
        
        return n - dp[n][n];
    }
};