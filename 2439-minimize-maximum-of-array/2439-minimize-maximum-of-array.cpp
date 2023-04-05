#define ll long long
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        ll n = size(nums), sum = nums[0], avg = nums[0];
        for(int i = 1; i<n; ++i)
        {
            sum += nums[i];
            avg = max(avg, sum/(i+1) + (sum % (i+1) > 0));
        }
        return avg;
    }
};