//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    bool isvalid(int x, int y, int n, int m, int i, int j, vector<vector<int>> &mat)
    {
        return x>=0 and y>=0 and x<n and y<m and (i==-1 || j==-1 || i==n || j==m || mat[i][j]<=mat[x][y]);
    }

    int water_flow(vector<vector<int>> &mat,int n,int m){
        queue<pair<pair<int, int>, int>> q;
        int cnt = 0;
        vector<vector<int>> hsh(n, vector<int>(m, 0)) ;
        
        vector<pair<int, int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(int i = 0; i<n; ++i) 
        {
            q.push({{i, -1}, 1});
            q.push({{i, m}, 2});
        }
        for(int i = 0; i<m; ++i) 
        {
            q.push({{-1, i}, 1});
            q.push({{n, i}, 2});
        }
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int i = curr.first.first, j = curr.first.second, oce = curr.second;
            if(oce == 3) ++cnt;
            for(auto it: move)
            {
                int x = it.first + i, y = it.second + j;
                if(isvalid(x, y, n, m, i, j, mat) && hsh[x][y]!=oce && hsh[x][y]!=3)
                {
                    hsh[x][y] |= oce;
                    q.push({{x, y}, hsh[x][y]});
                }
            }
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends