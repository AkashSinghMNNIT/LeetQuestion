class Solution {
public:
    
    vector<int> dis = {0, 1, 0, -1, 0};
    
    bool isvalid(int i, int j, int m, int n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }
    
    bool dfs(int i, int j, int n, int m, int &cnt, vector<vector<int>> &grid)
    {
        if(grid[i][j] == 0) return 1;
        grid[i][j] = 0;
        
        bool flag = 1;
        ++cnt;
        for(int k = 0; k<4; ++k)
        {
            int x = i + dis[k], y = j + dis[k+1];
            if(isvalid(x, y, m, n)) flag &= dfs(x, y, n, m, cnt, grid);
            else flag = 0;
        }
        return flag;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]), ans = 0;
        
        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                int cnt = 0;
                if(grid[i][j]) ans += (dfs(i, j, n, m, cnt, grid)?cnt:0);
            }
        }
        return ans;
    }
};