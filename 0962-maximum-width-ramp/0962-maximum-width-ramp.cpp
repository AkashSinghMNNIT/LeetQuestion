class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> v;
        int n = nums.size(), mn = n, ans = 0;
        for(int i = 0; i<n; ++i){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        for(auto it: v) 
        {
            ans = max(ans, it.second-mn);
            mn = min(mn, it.second);
        }
        return ans;
    }
};