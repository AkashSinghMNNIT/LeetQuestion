class Solution {
public:
    
    vector<int> fun(int i, vector<int> &nums)
    {
        if(__builtin_popcount(i)<2) return {};
        int j = 0;
        vector<int> v;
        while(i>0)
        {
            if(i&1) 
            {
                if(v.empty() || v.back()<=nums[j])
                v.push_back(nums[j]);
                else return {};
            }
            i/=2;
            ++j;
        }
        return v;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        map<vector<int>, int> mp;
        int en = (1<<n) - 1;
        for(int i = 3; i<=en; ++i)
        {
            vector<int> v = fun(i, nums);
            if(!v.empty()) mp[v]= 1;
        }
        for(auto [v, flag]: mp)ans.push_back(v);
        
        return ans;
    }
};