class Solution
{
    public:

        static bool cmp(vector<int> &a, vector<int> &b)
        {
            return (a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]);
        }

    int findLongestChain(vector<vector < int>> &p)
    {
        int n = size(p);
        sort(begin(p), end(p), cmp);
        vector<int> temp(n), dp(n, 1);
        for (int i = 0; i < n; ++i) temp[i] = p[i][1];

        for (int i = 0; i < n; ++i)
        {
            int j = lower_bound(begin(temp), end(temp), p[i][0]) - begin(temp) - 1;
            dp[i] = max((i>0?dp[i - 1]:1), 1 + (j >= 0 ? dp[j] : 0));
        }

        return dp[n - 1];
    }
};