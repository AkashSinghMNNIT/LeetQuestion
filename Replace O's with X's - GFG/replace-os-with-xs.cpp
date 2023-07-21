//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int vis[501][501] = {{0}};
    vector <vector <char>> grid;
    int m, n;
    void f(int i, int j){
        
        if(i<0 or j<0 or i>=m or j>=n) return;
        if(grid[i][j]=='X' || vis[i][j]) return;
        vis[i][j] = 1;
        f(i+1, j);
        f(i-1, j);
        f(i, j+1);
        f(i, j-1);
    }

    vector<vector<char>> fill(int M, int N, vector<vector<char>> mat)
    {
        // code here
        m = M;
        n = N;
        grid = mat;
        for(int i=0; i<m; i++){
            f(i, 0);
            f(i, n-1);
        }
        for(int j=0; j<n; j++){
            f(0, j);
            f(m-1, j);
        }
        for(int i = 1; i<m-1; ++i)
        {
            for(int j = 1; j<n-1; ++j)
            {
                if(grid[i][j]=='O' && !vis[i][j]) grid[i][j] = 'X';
            }
        }
        return grid;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends