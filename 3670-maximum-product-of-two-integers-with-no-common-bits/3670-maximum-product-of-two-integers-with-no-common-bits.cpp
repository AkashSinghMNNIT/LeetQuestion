class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end()), n = nums.size();
        int maxBit = log2(maxNum) + 1, mask = 1 << maxBit;
        vector<int> dp(mask, 0);
        for (auto it : nums)
            dp[it] = it;

        for (int bit = 0; bit <= maxBit; ++bit) {
            for (int curr = 0; curr < mask; ++curr) {
                if (curr & (1 << bit)) {
                    dp[curr] = max(dp[curr], dp[curr ^ (1 << bit)]);
                }
            }
        }
        long long ans = 0;
        for (auto it : nums) {
            int complement = (mask - 1) ^ it;
            ans = max(ans, it*1ll*dp[complement]);
        }
        return ans;
    }
};