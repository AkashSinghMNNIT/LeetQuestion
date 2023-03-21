class Solution
{
    public:
        int kthSmallest(vector<vector < int>> &mat, int k)
        {
            using vv = pair<int, vector < int>> ;
            priority_queue<vv, vector < vv>, greater < vv>> q;

            vector<int> v;
            set<vector < int>> vis;

            int m = size(mat), n = size(mat[0]), sum = 0;

            vector<int> curr(m, 0);
            for (int i = 0; i < m; ++i) sum += mat[i][curr[i]];

            q.push({ sum,
                curr });
            vis.insert(curr);
            while (v.size() < k)
            {
                if (q.empty()) return -1;
                curr = q.top().second;
                v.push_back(q.top().first);
                q.pop();
                for (int i = 0; i < m; ++i)
                {
                    if (curr[i] + 1 < n)
                    {
                        ++curr[i];
                        if (vis.find(curr) == vis.end())
                        {
                            sum = v.back() + mat[i][curr[i]] - mat[i][curr[i]-1];
                            q.push({ sum,
                                curr });
                            vis.insert(curr);
                        }
                        --curr[i];
                    }
                }
            }
            return v.back();
        }
};