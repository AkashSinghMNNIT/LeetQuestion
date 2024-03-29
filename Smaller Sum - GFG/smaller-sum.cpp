//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll long long
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<ll> pre(n+1), ans(n);
        vector<int> a = arr;
        sort(a.begin(), a.end());
        for(int i = 1; i<=n; ++i) pre[i] = pre[i-1] + a[i-1];
        
        for(int i = 0; i<n; ++i)
        {
            int idx = lower_bound(a.begin(), a.end(), arr[i])-a.begin();
            ans[i] = pre[idx];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends