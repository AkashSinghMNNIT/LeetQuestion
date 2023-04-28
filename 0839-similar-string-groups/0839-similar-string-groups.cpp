class Solution {
public:
    
    void dfs(int i, vector<int> g[], vector<int> &vis)
    {
        vis[i] = 1;
        for(auto it: g[i])
        {
            if(!vis[it]) dfs(it, g, vis);
        }
    }
    
    bool issame(string &a, string &b)
    {
        int pre = -1, n = size(a);
        for(int i = 0; i<n; ++i)
        {
            if(a[i] != b[i])
            {
                if(pre == n) return 0;
                else if(pre == -1)  pre = i;
                else if(a[pre] != b[i] || a[i]!=b[pre]) return 0;
                else pre = n;
               
            }
        }
        return 1;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> g[n];
        for(int i = 0; i<n; ++i)
        {
            for(int j = i+1; j<n; ++j)
            {
                if(issame(strs[i], strs[j])) 
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i<n; ++i)
        {
            if(!vis[i]) dfs(i, g, vis), ++ans;
        }
        return ans;
    }
};