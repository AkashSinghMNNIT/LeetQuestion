class Solution {
public:
    
    bool isvalid(vector<vector<int>> &grid, int i, int j, int m, int n )
    {
        return i>=0 && j>=0 && i<m && j<n && grid[i][j]==1; 
    }
    vector<pair<int, int>> move = { {0, 1}, {1, 0 }};
    
    
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        if((m+n)<=3) return 0;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        
        while(!q.empty())
        {
            int sz = q.size();
            if(sz == 1) ++cnt; 
            if(cnt >= 2) return 1;
            for(int i = 0; i<sz; ++i)
            {
                auto curr = q.front(); q.pop();
                for(auto it: move)
                {
                    int x = curr.first + it.first;
                    int y = curr.second + it.second;
                    if(x == m-1 && y == n-1) return 0;
                    if(isvalid(grid, x, y, m, n))
                    {
                        q.push({x, y});
                        grid[x][y] = 0;
                    }
                }
            }
        } 
        return 1;
    }
};