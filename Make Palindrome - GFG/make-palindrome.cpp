//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C

bool ispal(string s)
{
    int i = 0, j = s.length() - 1;
    while(i<j) if(s[i++] != s[j--]) return 0;
    return 1;
}

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        unordered_map<string, int> mp;
        for(auto it: arr) 
        {
            string s = it;
            reverse(s.begin(), s.end());
            if(mp[s]>0) mp[s]--;
            else mp[it]++;
        }
        vector<string> v;
        for(auto it: mp) 
        {
            if(it.second > 1) return 0;
            else if(it.second == 1) v.push_back(it.first);
        }
        if(v.size() > 1) return 0;
        else if(v.size() == 1) return ispal(v[0]);
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends