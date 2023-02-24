#define ll long long
class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            int n = nums.size();
            sort(begin(nums), end(nums));
            set<vector < int>> st;
            for (int i = 0; i < n - 3; ++i)
            {
                for (int j = i + 1; j < n - 2; ++j)
                {
                    ll l = j+1, r =n-1, tar = target+0ll-(nums[i]+nums[j]);
                    while (l<r)
                    {
                        ll x = nums[l] + 0ll + nums[r];
                        if (x == tar) st.insert({nums[i], nums[j], nums[l++], nums[r--]});
                        else if (x < tar) ++l;
                        else --r;
                    }
                }
            }
            vector<vector < int>> ans;
            for (auto it: st) ans.push_back(it);
            return ans;
        }
};