
// #define ll long long
// class Solution
// {
//     public:
//         int maxValueOfCoins(vector<vector < int>> &p, int K)
//         {
//             ll n = size(p), inf = 1e14, cnt = 0;
//             vector<vector < ll>> dp(n + 1, vector<ll> (K + 1, -inf));
//             for (auto &it: p)
//             {
//                 int pre = 0;
//                 for (auto &i: it) i += pre, pre = i;
//             }
//             for (int i = 0; i <= n; ++i) dp[i][0] = 0;
//            	// for(int i = 0; i<=K; ++i) dp[0][i] = 0;

//             for (int i = 1; i <= n; ++i)
//             {
//                 cnt += size(p[i-1]);
//                 for (int k = 1; k <= min(K*1ll, cnt); ++k)
//                 {
//                     dp[i][k] = dp[i - 1][k];
//                     for (int j = 1; j <= k; ++j)
//                     {
//                         dp[i][k] = max(dp[i][k], p[i - 1][j - 1] + dp[i - 1][k - j]);
//                     }
//                 }
//             }
//             return dp[n][K];
//         }
// };
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector dp(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; i++) {
            for (int coins = 0; coins <= k; coins++) {
                int currentSum = 0;
                for (int currentCoins = 0; currentCoins <= min((int)piles[i - 1].size(), coins); currentCoins++) {
                    if (currentCoins > 0) {
                        currentSum += piles[i - 1][currentCoins - 1];
                    }
                    dp[i][coins] = max(dp[i][coins], dp[i - 1][coins - currentCoins] + currentSum);
                }
            }
        }
        return dp[n][k];
    }
};