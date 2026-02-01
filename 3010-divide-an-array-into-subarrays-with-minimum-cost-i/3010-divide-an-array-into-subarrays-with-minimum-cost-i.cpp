class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mn = min(nums[1], nums[2]), smn = max(nums[1], nums[2]);
        for(int i = 3; i<nums.size(); ++i){
            if(nums[i]<=mn) smn = mn, mn = nums[i];
            else if(nums[i]<= smn) smn = nums[i];
        }
        return nums[0] + mn +smn;
    }
};