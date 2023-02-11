class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        
        for(auto it: redEdges) adj[it[0]].push_back({it[1], 0});
        for(auto it: blueEdges) adj[it[0]].push_back({it[1], 1});
        
        bool vis[n][2];
        memset(vis, 0, sizeof(vis));
        vis[0][0] = vis[0][1] = 1;
        vector<int> ans(n, -1);
        queue<pair<int, int>> q;
        vis[0][0] = vis[0][1] = 1;
        q.push({0, -1});
        int dis = 0;
        ans[0] = 0;
        while(!q.empty())
        {
            int sz = q.size();
            ++dis;
            for(int i = 0; i<sz; ++i)
            {
                auto curr = q.front();
                q.pop();
                for(auto it: adj[curr.first])
                {
                    if(vis[it.first][it.second] || it.second == curr.second) continue;
                    vis[it.first][it.second] = 1;
                    ans[it.first] = (ans[it.first]==-1?dis:ans[it.first]);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};