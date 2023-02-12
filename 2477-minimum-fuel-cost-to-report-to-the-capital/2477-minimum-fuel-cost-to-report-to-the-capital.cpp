class Solution {
public:
    
    long long dfs(int pre, int i, int seat, int depth, long long &ans, vector<int> adj[])
    {
        long long rider = 1;
        for(auto it: adj[i])
        {
            if(it == pre) continue;
            rider += dfs(i, it, seat, depth+1, ans, adj);
        }
        if(depth == 0) return ans;
        ans += (rider/seat)*depth + (rider%seat ? 1 : 0);
        
        return rider%seat;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        vector<int> adj[roads.size()+1];
        for(auto it: roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans = 0;
        return dfs(-1, 0, seats, 0, ans, adj);
    }
};