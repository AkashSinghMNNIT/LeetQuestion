class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2 * it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        vector<int> dist(n, 1e9);
        dist[0] = 0;
        q.push({0, dist[0]});
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            int d = top.first, node = top.second;
            if (d > dist[node])
                continue;
            if (node == n - 1)
                return d;
            for (auto it : adj[node]) {
                if (dist[it.first] > d + it.second) {
                    dist[it.first] = d + it.second;
                    q.push({d + it.second, it.first});
                }
            }
        }
        return -1;
    }
};