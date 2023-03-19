class Solution
{
    public:

        int dfs(vector<int> adj[], int mask, int i, int &node, int &res)
        {
            int dia = 0, mx = 0;
            ++node;
            for (auto it: adj[i])
            {
                if (mask & (1 << it))
                {
                    dia = 1 + dfs(adj, mask ^ (1 << it), it, node, res);
                    res = max(res, dia + mx);
                    mx = max(mx, dia);
                }
            }
            return mx;
        }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector < int>> &edges)
    {
        vector<int> adj[n];
        for (auto it: edges)
        {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<int> ans(n - 1);
        for (int s = 3; s < (1 << n); ++s)
        {
            for (int i = 0; i < n; ++i)
            {
               	// if(__builtin_popcount(s) == 1) continue;
                if (s &(1 << i))
                {
                    int dia = 0, node = 0;

                    dfs(adj, s ^ (1 << i), i, node, dia);
                    if (dia > 0 && __builtin_popcount(s) == node) ans[dia - 1]++;
                    break;
                }
            }
        }
        return ans;
    }
};