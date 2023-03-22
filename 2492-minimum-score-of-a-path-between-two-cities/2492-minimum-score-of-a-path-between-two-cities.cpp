class Solution {
public:
    
    void dfs(vector<pair<int, int>> adj[], int &ans, vector<int> &vis, int i)
    {
        if(vis[i]) return;
        vis[i] = 1;
        for(auto it: adj[i])
        {
            // if(!vis[it.first])
            ans = min(ans, it.second);
            
            dfs(adj, ans, vis, it.first);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n+1];
        vector<int> vis(n+1, 0);
        int m = roads.size();
        for(int i = 0; i<m; ++i)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        int ans = INT_MAX;
        dfs(adj, ans, vis, 1);
        return ans;
    }
};