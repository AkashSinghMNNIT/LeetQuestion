class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[1]==b[1]?a[0]<b[0]:a[1]<b[1]);
    }
    
    int findLongestChain(vector<vector<int>>& p) {
        int n = size(p);
        sort(begin(p), end(p), cmp);
        // vector<int> temp(n);
        // for(int i = 0; i<n; ++i) temp[i] = p[i][1];
        int l = -1e4, ans = 0;
        for(auto it: p)
        {
            cout<<it[0]<<","<<it[1]<<"  ";
            if(it[0] > l) ++ans, l = it[1];
        }
        cout<<endl;
        return ans;
    }
};