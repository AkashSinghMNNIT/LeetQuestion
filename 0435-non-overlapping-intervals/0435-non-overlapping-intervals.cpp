class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[1]==b[1]? a[0]<b[0]:a[1]<b[1]);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = size(a), ans = 0, l = -1e6;
        sort(begin(a), end(a), cmp);
        
        for(int i = 0; i<n; ++i)
        {
            if(a[i][0] < l) ++ans;
            else l = a[i][1];
        }
        return ans;
    }
};