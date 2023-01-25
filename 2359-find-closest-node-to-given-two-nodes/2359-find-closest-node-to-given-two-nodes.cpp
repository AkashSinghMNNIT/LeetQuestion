class Solution {
public:
    
    void bfs(vector<int> &e, int a[], int idx)
    {
        queue<int> q;
        q.push(idx);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(e[curr]==-1) continue;
            if(a[e[curr]]>=(1+a[curr])) 
            {
                q.push(e[curr]);
                a[e[curr]] = 1+a[curr];
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), ans = n+1, res = n;
        int a[n], b[n];
        fill(a, a+n, n);
        fill(b, b+n, n);
        a[node1] = b[node2] = 0;
        bfs(edges, a, node1);
        bfs(edges, b, node2);
        for(int i = 0; i<n; ++i)
        {
            int mx = max(a[i], b[i]);
            if(mx<ans && mx!=n) ans = mx, res = i;
            else if(mx == ans) res = min(res, i);
        }
        if(ans == n+1) return -1;
        return res;
    }
};