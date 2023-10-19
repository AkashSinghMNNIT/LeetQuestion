//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    queue<int> q;
	    q.push(0);
	    int level = 0, hsh[v] = {0};
	    while(!q.empty())
	    {
	        int sz = q.size();
	        while(sz--)
	        {
	            int curr = q.front();
	            hsh[curr] = 1;
	            q.pop();
	            if(curr == x) return level;
	            for(auto it: adj[curr]) if(hsh[it]==0)q.push(it);
	        }
	        ++level;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends