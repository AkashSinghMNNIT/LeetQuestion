class Solution {
public:
    
    bool check(int a[], int b[])
    {
        for(int i = 0; i<26; ++i) if(a[i] != b[i]) return 0;
        return 1;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int a[26] = {0}, b[26] = {0};
        for(auto it: p) a[it-'a']++;
        int m = p.length(), n = s.length();
        vector<int> ans;
        for(int i = 0; i<n; ++i)
        {
            if(i>=m) b[s[i-m]-'a']--;
            b[s[i]-'a']++;
            if(i >= m-1 && check(a, b))  ans.push_back(i-m+1);
        }
        return ans;
    }
};