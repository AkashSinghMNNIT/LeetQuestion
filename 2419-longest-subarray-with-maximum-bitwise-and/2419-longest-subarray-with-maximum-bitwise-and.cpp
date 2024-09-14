class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), cnt = 0, ans = 1;
        for(int i =0; i<nums.size(); ++i)
        {
            if(nums[i]==mx) ++cnt;
            else cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};