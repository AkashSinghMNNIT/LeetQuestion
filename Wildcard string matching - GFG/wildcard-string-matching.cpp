//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pat)
    {
        int n = wild.length(), m = pat.length();
        int arr[n+1][m+1];
        arr[0][0] = 1;
        for(int i = 1; i<m; ++i) arr[0][i] = 0;
        for(int i = 1; i<=n; ++i) arr[i][0] = arr[i-1][0] && (wild[i-1]=='*');
        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1; j<=m; ++j)
            {
                if(wild[i-1] == '?') arr[i][j] = arr[i-1][j-1];
                else if(wild[i-1] == '*') arr[i][j] = arr[i][j-1] || arr[i-1][j-1] || arr[i-1][j];
                else arr[i][j] = arr[i-1][j-1] && (wild[i-1] == pat[j-1]);
            }
        }
        return arr[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends