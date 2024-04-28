class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> cnt(n, vector<int>(10));
        for(int j = 0; j<n; ++j)
        {
            for(int i = 0; i<m; ++i) cnt[j][grid[i][j]]++;
            if(j == 0) continue;
            for(int i = 0; i<10; ++i)
            {
                int mx = 0;
                for(int k = 0; k<10; ++k)
                if(i!=k) mx = max(mx, cnt[j-1][k]);
                cnt[j][i] += mx;
            }
        }
        for(int i = 0; i<10; ++i) ans = max(ans, cnt[n-1][i]);
        return m*n-ans;
    }
};