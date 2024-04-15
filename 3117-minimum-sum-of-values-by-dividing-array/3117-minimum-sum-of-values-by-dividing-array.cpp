class Solution {
public:
    vector<vector<unordered_map<int, int>>> dp;
    set<int> st;
    int helper(vector<int>& nums, vector<int>& vals, int i, int j, int mask) {
        int n = nums.size(), m = vals.size();
        if (i == n && m == j)
            return 0;
        if (i == n || m == j)
            return 1e7;
        if(dp[i][j].count(mask)) return dp[i][j][mask];
        st.insert(mask & nums[i]);
        int ans = 1e7;
        if ((mask & nums[i]) < vals[j])
            ans = 1e7;
        else if ((mask & nums[i]) == vals[j])
            ans = min(nums[i] +
                           helper(nums, vals, i + 1, j + 1, (1 << 18) - 1),
                       helper(nums, vals, i + 1, j, mask & nums[i]));
        else
            ans = helper(nums, vals, i + 1, j, mask & nums[i]);
        return dp[i][j][mask] = ans;
    }
    int minimumValueSum(vector<int>& nums, vector<int>& vals) {
        int n = nums.size(), m = vals.size();
        dp.resize(n, vector<unordered_map<int, int>>(m));
        int ans = helper(nums, vals, 0, 0, (1 << 18) - 1);
        cout<<st.size()<<endl;
        if (ans == 1e7)
            return -1;
        else
            return ans;
    }
};