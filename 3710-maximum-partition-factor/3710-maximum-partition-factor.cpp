class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        void merge(int a, int b) {
            a = find(a), b = find(b);
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };
    int maxPartitionFactor(vector<vector<int>>& p) {
        int n = p.size();
        if (n == 2)
            return 0;
        vector<tuple<int, int, int>> dis;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                dis.push_back({dist, i, j});
            }
        }
        sort(dis.begin(), dis.end());

        DSU dsu(n);
        unordered_map<int, int> mp;
        for (auto& [dist, u, v] : dis) {
            if (dsu.find(u) == dsu.find(v))
                return dist;

            if (mp.count(u))
                dsu.merge(v, mp[u]);
            if (mp.count(v))
                dsu.merge(u, mp[v]);
            mp[u] = v;
            mp[v] = u;
        }
        auto [f, i, j] = dis.back();
        return f;
    }
};