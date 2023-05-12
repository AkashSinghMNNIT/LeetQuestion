//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int pre = -1, ans = 0;
        for(int i = 0; i<n; ++i)
        {
            if(arr[i] == 0) 
            {
                if(pre+1 != i) ++ans;
                pre = i;
            }
        }
        if(pre != n-1)++ans;
        return (ans>1 || pre!=-1)?ans:-1;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends