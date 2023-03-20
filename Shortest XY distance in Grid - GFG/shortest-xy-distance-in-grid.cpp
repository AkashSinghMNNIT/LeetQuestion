//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool isvalid(int x, int y, int n, int m, vector<vector<char>> &grid)
  {
      return x>=0 and y>=0 and x<n and y<m and grid[x][y]!='.';
  }
  
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<m; ++j)
            {
                if(grid[i][j] == 'X') grid[i][j] = '.', q.push({{i, j}, 0});
            }
        }
        int move[5] = {0, 1, 0, -1, 0};
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int i = curr.first.first, j = curr.first.second, dis = curr.second;
            for(int k = 0; k<4; ++k)
            {
                int x = i+move[k], y = j+move[k+1];
                if(isvalid(x, y, n, m, grid))
                {
                    if(grid[x][y] == 'Y') return dis+1;
                    else q.push({{x, y}, dis+1});
                    grid[x][y] = '.';
                }
            }
        }
        return n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends