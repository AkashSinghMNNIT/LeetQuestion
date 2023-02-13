//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        int arr[n+1][3];
        arr[0][0] = arr[0][1] = arr[0][2] = 0;
        for(int i = 1; i<=n; ++i)
        {
            arr[i][0] = colors[i-1][0] + min(arr[i-1][1], arr[i-1][2]);
            arr[i][1] = colors[i-1][1] + min(arr[i-1][0], arr[i-1][2]);
            arr[i][2] = colors[i-1][2] + min(arr[i-1][0], arr[i-1][1]);
        }
        return min(arr[n][0], min(arr[n][1], arr[n][2]));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends