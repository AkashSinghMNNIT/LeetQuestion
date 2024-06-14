class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size(), mx, ans = 0;
        sort(nums.begin(), nums.end());
        mx = nums[0];
        for(int i = 1; i<n; ++i)
        {
            if(nums[i]<=mx) ans += mx-nums[i]+1;
            mx = max(mx+1, nums[i]);
        }
        return ans;
    }
};