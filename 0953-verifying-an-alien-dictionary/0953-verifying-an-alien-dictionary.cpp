class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> mp;
        for(int i = 0; i<26; ++i) mp[order[i]] = 'a'+i;
        
        string p = "";
        for(auto it: words)
        {
            string s = "";
            for(auto i: it) s.push_back(mp[i]);
            if(s<p) return 0;
            p = s;
        }
        return 1;
    }
};