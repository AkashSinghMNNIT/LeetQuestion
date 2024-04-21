#define ll long long
class Solution {
public:
    void dijkstra(const vector<pair<int, int>> graph[], int source, vector<ll>& distances) {
        int n = distances.size();
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        distances.assign(n, INT_MAX);
        distances[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();

            if (dist_u != distances[u]) continue; // Skip outdated updates

            for (auto edge : graph[u]) {
                int v = edge.first;
                int weight_uv = edge.second;
                if (distances[u] + weight_uv < distances[v]) {
                    distances[v] = distances[u] + weight_uv;
                    pq.push({distances[v], v});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<ll> dis(n);
        dijkstra(adj, 0, dis);
        map<pair<int, int>, bool> mp;
        queue<int> q;
        q.push(n-1);
        vector<bool> vis(n, 0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto it: adj[u]){
                if(dis[it.first]+it.second == dis[u]) {
                    mp[{it.first, u}] = 1;
                    q.push(it.first);
                }
            }
        }
        vector<bool> ans(edges.size(), 0);
        for(int i = 0; i<edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1];
            ans[i] = mp.count({u, v}) || mp.count({v, u});
        }
        return ans;
    }
};