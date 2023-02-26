//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define pb push_back
class Solution {
  public:
  
    void dfs(int i, vector<vector<int>> &gr, vector<int> &vis, vector<int> &comp)
    {
        if(vis[i] == 1) return;
        vis[i] = 1;
        comp.pb(i);
        for(auto it: gr[i]) dfs(it, gr, vis, comp);
        
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        
        vector<int> vis(V+2, 0);
        int ans = 0;
        for(int i = 1; i<=V; ++i)
        {
            if(vis[i]==1) continue;
            vector<int> comp;
            dfs(i, adj, vis, comp);
            int sz = comp.size();
            ++ans;
            for(auto it: comp)
            {
                if(adj[it].size() != sz-1) 
                {
                    ans--;
                    break;
                }
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends