class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, val, n = nums.size();
        for(auto it: nums)
        {
            if(cnt == 0) cnt = 1, val = it;
            else if(val == it) ++cnt;
            else --cnt;
        }
        return val;
    }
};