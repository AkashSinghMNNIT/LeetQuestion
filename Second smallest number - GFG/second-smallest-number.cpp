//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        string ans(d, '0');
        if(s == 0 || s==1 || d*9 <= s) return "-1";
        
        ans[0] = '1';
        int i = d-1, sum = s-1, cnt = 0;
        while(i>0 && sum>0) ans[i--] = ('0'+min(sum, 9)), sum -= min(sum, 9);
        
        if(sum > 0) ans[0] = ('0' + (sum+1));
        i = d-1;
        char mx = ans[i];
        while(i>=0)
        {
            if(ans[i] < mx) 
            {
                ans[i] += 1;
                ans[i+1] -= 1;
                break;
            }
            --i;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends