class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int minIdx = n-1;
        for(int i = n-2; i>=0; --i){
            int mx = min(n-1, nums[i]+i);
            if(mx>=minIdx) minIdx = i;
        }
        return minIdx==0;
    }
};