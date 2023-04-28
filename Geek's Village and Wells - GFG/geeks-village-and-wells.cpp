//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    bool isvalid(int x, int y, int n, int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        int move[5] = {0, 1, 0, -1, 0};
        int inf = 1e8;
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<m; ++j)
            {
                if(c[i][j] == 'W') q.push({i, j});
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            for(int i = 0; i<4; ++i)
            {
                int x = move[i] + it.first, y = move[i+1] + it.second;
                if(!isvalid(x, y, n, m) || c[x][y] == 'N' || c[x][y] == 'W') continue;
                else if(dis[x][y]==0) dis[x][y] = 1 + dis[it.first][it.second], q.push({x, y});
            }
        }
        for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j)
        if(c[i][j] != 'H') dis[i][j] = 0;
        else dis[i][j] = dis[i][j]?2*dis[i][j]:-1;
        
        return dis;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends