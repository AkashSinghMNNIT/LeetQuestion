//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> st;
        
        for(int i = 0; i<n; ++i)
        {
            while(!st.empty() && m[st.top()][i] == 1) st.pop();
            if(st.empty()) st.push(i);
        }
        for(int i = 0; i<n; ++i) if(i!=st.top() && (m[i][st.top()]==0 || m[st.top()][i]==1)) return -1;
        return st.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends