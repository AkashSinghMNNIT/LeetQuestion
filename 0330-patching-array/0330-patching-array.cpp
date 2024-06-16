class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long ans = 0, len = nums.size(), curr = 1, i = 0;
        while(curr<=n)
        {
            if(i<len && nums[i]<=curr) curr += nums[i++];
            else curr *= 2, ++ans;
        }
        return ans;
    }
};