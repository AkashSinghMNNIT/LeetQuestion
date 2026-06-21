class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), jump = 0, currlevel = 0, nextlevel = 0;
        for(int i = 0; i<n-1; ++i){
            nextlevel = max(nextlevel, nums[i]+i);
            if(i == currlevel){
                currlevel = nextlevel;
                if(currlevel==i) break;
                ++jump;
            }
        }
        if(currlevel<n-1) return -1;
        return jump;
    }
};