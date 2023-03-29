//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int n = s.length(), ans = 0;
        for(int i = 0; i<n; ++i)
        {
            int l = 0, u = 0;
            for(int j = i; j<n; ++j)
            {
                if(s[j]>='a') ++l;
                else ++u;
                if(l == u) ++ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends