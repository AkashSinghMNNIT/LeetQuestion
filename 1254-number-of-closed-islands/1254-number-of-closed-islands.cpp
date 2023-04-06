class Solution {
public:
    
    vector<int> dis = {0, 1, 0, -1, 0};
    
    bool isvalid(int x, int y, int n, int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    bool dfs(int i, int j, vector<vector<int>>&grid)
    {
        bool flag = 1;
        if(grid[i][j] == 1) return 1;
        grid[i][j] = 1;
        int n = grid.size(), m = size(grid[0]);
        
        for(int k = 0; k<4; ++k)
        {
            int x = i+dis[k], y = j+dis[k+1];
            if(isvalid(x, y, n, m)) flag &= dfs(x, y, grid);
            else flag = 0;
        }
        
        return flag;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = size(grid[0]), ans = 0;
        for(int i = 0;i<n; ++i)
        {
            for(int j = 0; j<m ; ++j)
            {
                if(grid[i][j] == 0) ans += dfs(i,j,grid);
            }
        }
        return ans;
    }
};