#define f first
#define s second
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it: fl) adj[it[0]].push_back({it[1], it[2]});
        int stops = 0;
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        queue<int> q;
        q.push(0);
        while(stops<=k and !q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int curr = q.front();
                q.pop();
                for(auto n: adj[curr])
                {
                    if(dis[n.f] > dis[curr]+n.s)
                    {
                        dis[n.f] = dis[curr]+n.s;
                        q.push(n.f);
                    }
                }
            }
            stops++;
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};