//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int m = s.length(), ans,b, a, l, o, n;
        ans = m/6, b = a = l = o = n = 0;
        
        for(auto i: s)
        {
            if(i == 'b') ++b;
            else if(i == 'a') ++a;
            else if(i == 'l') ++l;
            else if(i == 'o') ++o;
            else if(i == 'n') ++n;
        }
        l >>= 1, o >>= 1;
        ans = min(ans, min(b, min(a, min(l, min(o, n)))));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends