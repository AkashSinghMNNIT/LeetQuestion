//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        int n = s.length();
        string ans = "";
        for(auto it: s)
        {
            if(ans.length()>0 && ans.back()==it) ans.pop_back();
            else ans.push_back(it);
        }
        return ans.size()?ans:"-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends