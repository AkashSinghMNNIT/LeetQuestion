class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(begin(v), end(v));
        int n = size(v), ans = 0, sum = 0;
        for(int i = n-1; i>=0; --i)
        {
            if(ans + v[i] + sum >= ans) ans += v[i]+sum, sum += v[i];
            else break;
        }
        return ans;
    }
};