class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0, ans = -1;
        sort(nums.begin(), nums.end());
        for(auto it: nums)
        {
            if(it < sum) ans = max(ans, sum+it);
            sum += it;
        }
        return ans;
    }
};