class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int j = 0; j<200; ++j)
        {
            if(j>=strs[0].size()) return ans;
            char ch = strs[0][j];
            for(auto it: strs)
            {
                if(j>=it.size()) return ans;
                if(ch != it[j]) return ans;
            }
            ans += ch;
        }
        return ans;
    }
};