class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int n = p.size(),ans = 0;
        for(int i = 1; i<n; ++i){
            int x = abs(p[i][0]-p[i-1][0]), y = abs(p[i][1]-p[i-1][1]);
            ans += min(x, y);
            ans += abs(x-y);
        }
        return ans;
    }
};