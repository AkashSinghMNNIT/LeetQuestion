//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string s){
        string ans = ""; char ch = s[0];
        int n = s.length();
        ans += s[0];
        for(int i = 1; i<n; ++i)
        {
            if(s[i]<s[i-1]) ans += s[i];
            else if(s[i] == s[i-1] && s[i]<ch) ans += s[i];
            else break;
        }
        string t = ans;
        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends