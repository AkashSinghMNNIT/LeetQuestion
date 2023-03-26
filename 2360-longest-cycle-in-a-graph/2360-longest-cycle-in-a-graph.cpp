class Solution {
public:
    int ans = -1;
    
    void dfs(int time[], vector<int> &e, int vis[], int i, int t)
    {
        if(vis[i]) return;
        if(time[i]) 
        {
            ans = max(ans, t+1-time[i]);
            return;
        }
        ++t;
        time[i] = t;
        if(e[i]!=-1) dfs(time, e, vis, e[i], t);
        vis[i] = 1;
    }
    
    int longestCycle(vector<int>& e) {
        int n = size(e), t = 0;
        int time[n], vis[n];
        fill(time, time+n, 0);
        fill(vis, vis+n, 0);
        for(int i = 0; i<n; ++i)
        {
            if(!time[i]) dfs(time, e, vis, i, t);
        }
        return ans;
    }
};