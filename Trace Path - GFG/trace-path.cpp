//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int i = 0, j = 0, mnx = 0, mxx = 0, mny = 0, mxy = 0;
        
        for(auto it: s)
        {
            if(it == 'L') --j;
            else if(it == 'R') ++j;
            else if(it == 'U') ++i;
            else --i;
            mnx = min(mnx, i), mxx = max(mxx, i);
            mny = min(mny, j), mxy = max(mxy, j);
        }
        return (mxx-mnx)<n && (mxy-mny)<m;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends