class Solution {
public:
    string removeStars(string s) {
        int n = s.length(), cnt = 0;
        string ans;
        for(int i = n-1; i>=0; --i)
        {
            if(s[i] == '*') ++cnt;
            else if(cnt) --cnt;
            else ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};