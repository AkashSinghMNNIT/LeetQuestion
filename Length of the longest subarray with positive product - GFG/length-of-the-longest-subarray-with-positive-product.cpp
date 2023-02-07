//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
          int i = 0,j = 0, left = -1,ans = 0, right = 0, cnt = 0;
          for(i = 0; i<n; ++i)
          {
              if(arr[i]==0) 
              {
                  j = i+1;
                  right = i+1;
                  left = -1;
                  cnt = 0;
                  continue;
              }
              else if(arr[i]<0)
              {
                  if(left == -1) left = i;
                  right = i;
                  ++cnt;
              }
              if(cnt & 1) ans = max(ans, max(right - j, i-left));
              else ans = max(ans, i-j+1);
          }
          return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends