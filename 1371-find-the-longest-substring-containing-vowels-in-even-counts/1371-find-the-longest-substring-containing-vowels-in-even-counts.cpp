class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, int> mp = {{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        map<int, int> hsh = {{0, 0}};
        int n = s.length(), ans = 0, xo = 0;
        for(int i = 0; i<n; ++i)
        {
            xo ^= mp[s[i]];
            if(hsh.count(xo))
            ans = max(ans, i+1-hsh[xo]);
            else hsh[xo] = i+1;
        }
        return ans;
    }
};