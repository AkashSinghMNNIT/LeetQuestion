class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        int k = nums.size(), cnt = 0;
        vector<int> ans = {-100000, 100000};
        for(int i = 0; i<k; ++i)
        {
            for(auto it: nums[i]) v.push_back({it, i});
        }
        sort(v.begin(), v.end());
        vector<int> hsh(k, 0);
        for(int i = 0, j = 0; i<v.size(); ++i)
        {
            while(j<v.size() && cnt<k)
            {
                ++hsh[v[j].second];
                cnt += (hsh[v[j++].second] == 1);
            }
            if(cnt==k && (ans[1]-ans[0])>(v[j-1].first-v[i].first))ans = {v[i].first, v[j-1].first};
            --hsh[v[i].second];
            cnt -= (hsh[v[i].second]==0);
        }
        return ans;
    }
};