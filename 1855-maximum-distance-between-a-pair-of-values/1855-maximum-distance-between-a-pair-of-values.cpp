class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(), ans = 0, i = 0;
        for(int j = 0; j<m; ++j){
            while(i<n && i<=j && a[i]>b[j]) ++i;
            if(i<=j && i<n && a[i]<=b[j]) ans = max(ans, j-i);
        }
        return ans;
    }
};