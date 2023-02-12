class Solution {
public:
    // vector<int> vis;
    int vis[100002];
    int fun(vector<int> adj[], int idx, long long &ans, int seat)
    {
        if(vis[idx]) return 0;
        vis[idx] = 1;
        int rider = 1;
        for(auto i: adj[idx])
        {
            int x = fun(adj, i, ans, seat);
            ans += x/seat + (x%seat>0);
            rider += x;
        }
        return rider;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        // vis.resize(n);
        // fill(vis.begin(), vis.end(), 0);
        // memset(vis, 0, sizeof(vis));
        long long ans = 0, cnt = 0, dis = 0;
        vector<int> adj[n+1];
        for(auto it: roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        fun(adj, 0, ans, seats);
        return ans;
    }
};