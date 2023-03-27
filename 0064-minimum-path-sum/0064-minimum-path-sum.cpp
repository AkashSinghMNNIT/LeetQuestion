class Solution
{
    public:
        int minPathSum(vector<vector < int>> &grid)
        {
            int m = size(grid), n = size(grid[0]), inf = 1e6;
            vector<vector < int>> dp(m, vector<int> (n, inf));
            dp[0][0] = grid[0][0];
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if(i==0 && j==0) continue;
                    dp[i][j] = min(dp[i][j], grid[i][j] + (i == 0 ? inf : dp[i - 1][j]));
                    dp[i][j] = min(dp[i][j], grid[i][j] + (j == 0 ? inf : dp[i][j - 1]));
                }
            }
            return dp[m - 1][n - 1];
        }
};