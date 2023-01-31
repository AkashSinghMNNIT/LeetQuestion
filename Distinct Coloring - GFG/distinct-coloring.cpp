//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        long long int arr[n][3];
        arr[0][0] = r[0], arr[0][1] = g[0], arr[0][2] = b[0];
        for(int i = 1; i<n; ++i)
        {
            arr[i][0] = r[i] +0ll+ min(arr[i-1][1], arr[i-1][2]);
            arr[i][1] = g[i] +0ll+ min(arr[i-1][0], arr[i-1][2]);
            arr[i][2] = b[i] +0ll+ min(arr[i-1][0], arr[i-1][1]);
        }
        return min(arr[n-1][0], min(arr[n-1][1], arr[n-1][2]));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends