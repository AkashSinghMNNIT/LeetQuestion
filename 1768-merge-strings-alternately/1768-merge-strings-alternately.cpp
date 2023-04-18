class Solution {
public:
    string mergeAlternately(string a, string b) {
        string ans = "";
        int i = 0, j = 0, n = a.length(), m = b.length();
        while(i<n && j<m) ans += a[i++] , ans += b[j++];
        while(i<n) ans += a[i++];
        while(j<m) ans += b[j++];
        return ans;
    }
};