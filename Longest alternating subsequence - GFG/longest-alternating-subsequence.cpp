//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int mn = 1, mx = 1, n = nums.size();
		    for(int i = 1; i<n; ++i)
		    {
		        if(nums[i] > nums[i-1]) mx = 1 + mn;
		        else if(nums[i] < nums[i-1]) mn = 1+mx;
		    }
		  
		    return max(mn, mx);
		}
		

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends