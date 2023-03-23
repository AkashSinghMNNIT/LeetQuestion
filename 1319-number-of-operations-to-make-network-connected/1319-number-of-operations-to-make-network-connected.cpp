class Solution {
public:
    
    void dfs(int idx, vector<int> adj[], vector<int> &vis)
    {
        vis[idx] = 1;
        for(auto it: adj[idx]) if(!vis[it]) dfs(it, adj, vis);
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        int x = c.size(), cnt = 0;
        if(x < n-1) return -1;
        vector<int> adj[n];
        for(auto it: c)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        for(int i = 0; i<n; ++i)
        {
            if(!vis[i]) ++cnt, dfs(i, adj, vis);
        }
        return cnt-1;
    }
};