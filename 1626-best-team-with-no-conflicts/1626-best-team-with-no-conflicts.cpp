class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size(), ans = 0;
        vector<vector<int>> arr(n+1, vector<int>(2, 0));
        
        for(int i = 1; i<=n; ++i) arr[i][1] = scores[i-1], arr[i][0] = ages[i-1];
        sort(arr.begin(), arr.end());
        int dp[n+1];
        fill(dp, dp+n+1, 0);
        for(int i = 1; i<=n; ++i)
        {
            for(int j = i; j>0; --j)
            {
                if(arr[i][0] > arr[j][0] && arr[i][1] < arr[j][1]) continue;
                dp[i] = max(dp[i], dp[j] + arr[i][1]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};