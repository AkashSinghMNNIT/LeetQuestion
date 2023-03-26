//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    stack<int> gr, sm;
		    int n = nums.size(), ans = 1;
		    int pgr[n], psm[n];
		    for(int i = 0; i<n; ++i)
		    {
		        while(!gr.empty() && nums[gr.top()] <= nums[i]) gr.pop();
		        if(gr.empty()) pgr[i] = -1;
		        else pgr[i] = gr.top();
		        
		        gr.push(i);
		        
		        while(!sm.empty() && nums[sm.top()] >= nums[i]) sm.pop();
		        if(sm.empty()) psm[i] = -1;
		        else psm[i] = sm.top();
		        
		        sm.push(i);
		    }
		    
		    vector<vector<int>> dp(n, vector<int>(2, 0));
		    
		    for(int i = 0; i<n; ++i)
		    {
		        if(psm[i]!=-1) dp[i][0] = max(1+dp[psm[i]][1], dp[psm[i]][0]);
		        else dp[i][0] = 1;
		        
		        if(pgr[i]!=-1) dp[i][1] = max(1+dp[pgr[i]][0], dp[pgr[i]][1]);
		        else dp[i][1] = 1;
		        ans = max({ans, dp[i][0], dp[i][1]});
		    }
		  
		    return ans;
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