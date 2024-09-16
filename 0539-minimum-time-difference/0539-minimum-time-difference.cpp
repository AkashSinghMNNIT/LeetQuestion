class Solution {
public:
    int toMinutes(string s)
    {
        return 60*stoi(s.substr(0,2)) + stoi(s.substr(3,2));
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size(), ans = 3600;
        vector<int> v;
        for(auto it: timePoints) v.push_back(toMinutes(it));
        sort(v.begin(), v.end());
        for(int i = 1; i<n; ++i) ans = min(ans, v[i]-v[i-1]);
        ans = min(ans, 1440-v.back() + v[0]);
        return ans;
    }
};