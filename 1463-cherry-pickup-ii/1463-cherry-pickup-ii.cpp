class Solution {
public:
    bool isvalid(int x, int y, int m) {
        return x >= 0 && y >= 0 && x < m && y < m;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> curr(m, vector<int>(m, -1)), pre;
        pre = curr;
        pre[0][m - 1] = grid[0][0] + grid[0][m - 1];
        int dir[3] = {-1, 0, 1};
        for (int i = 1; i < n; ++i) {
            for (int a = 0; a < m; ++a) {
                for (int b = 0; b < m; ++b) {
                    if (pre[a][b] != -1) {
                        for (auto adir : dir) {
                            for (auto bdir : dir) {
                                int x = a + adir, y = b + bdir;
                                if (isvalid(x, y, m)) {
                                    if (x == y)
                                        curr[x][y] = max(curr[x][y],pre[a][b] + grid[i][x]);
                                    else
                                        curr[x][y] = max(curr[x][y],pre[a][b] + grid[i][x] + grid[i][y]);
                                }
                            }
                        }
                    }
                }
            }
            pre = curr;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                ans = max(ans, curr[i][j]);
        return ans;
    }
};