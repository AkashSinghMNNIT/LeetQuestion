class Solution
{
    public:
        
        bool isvalid(int x, int y, int n)
        {
            return x>=0 and y>=0 and x<n and y<n;
        }
    
        int maxDistance(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int a[n][n];
            for (int i = 0; i < n; ++i) fill(a[i], a[i] + n, -1);
            queue<pair<int, int>> q;
            vector<pair<int, int>> move = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (grid[i][j] == 1)
                    {
                        a[i][j] = 0;
                        q.push({ i, j });
                    }
                }
            }
            int sz = q.size(), dis = 0, ans = 0;
            
            if((sz == 0) || (sz == n*n)) return -1;
            while(!q.empty())
            {
                sz = q.size(), ++dis;
                for(int i = 0; i<sz; ++i)
                {
                    auto curr = q.front();
                    q.pop();
                    for(auto it: move)
                    {
                        int x = it.first + curr.first;
                        int y = it.second + curr.second;
                        if(isvalid(x, y, n) && a[x][y]==-1)
                        {
                            a[x][y] = dis;
                            ans = max(ans, dis);
                            q.push({x, y});
                        }
                    }
                }
            }
            return ans;
        }
};