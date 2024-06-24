class Solution {
public:
    int minKBitFlips(vector<int>& v, int k) {
        int n = v.size(), ans = 0;
        vector<int> pre(n+2, 0);
        for(int i = 1; i<=n-k+1; ++i)
        {
            pre[i] += pre[i-1];
            if(v[i-1] == (pre[i]&1))
            ++pre[i], --pre[i+k], ++ans;
        }
        for(int i = n-k+2; i<=n; ++i)
        {
            pre[i] += pre[i-1];
            if(v[i-1] == (pre[i]&1)) ans = -1;
        }
        return ans;
    }
};