class Solution {
public:
    int partitionString(string s) {
        int n = s.length(), ans = 1;
        unordered_map<char, int> mp;
        for(auto it: s)
        {
            if(mp[it]) mp.clear(), ++ans;
            mp[it] = 1;
        }
        return ans;
    }
};