//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       int odd = 0, even = 0, n = x.length();
       for(int i = 0; i<n; ++i)
       {
           if(i&1) even += x[i]-'0';
           else odd += x[i]-'0';
       }
       
       return (11 + (even - odd)%11) %11;
    
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends