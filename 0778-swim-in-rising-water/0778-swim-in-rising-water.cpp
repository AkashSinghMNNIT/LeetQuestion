class Solution {
public:
    bool isvalid(int i, int j, int n)
    {
        return i>=0 && j>=0 && i<n && j<n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 3000));
        ans[0][0] = grid[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({ans[0][0], 0});
        int dir[5] = {0, 1, 0, -1, 0};
        while(!q.empty())
        {
            auto [val, node] = q.top();
            q.pop();
            int x = node/n, y = node%n;
            if(x==n-1 && y==n-1) return val;
            for(int neig = 0; neig<4; ++neig){
                int i = x+dir[neig], j = y+dir[neig+1], currnode = i*n + j;
                if(!isvalid(i, j, n))continue;
                int currVal = max(val, grid[i][j]);
                if(currVal < ans[i][j]){
                    q.push({currVal, currnode});
                    ans[i][j] = currVal;
                }
            }
        }
        return ans[n-1][n-1];
    }
};