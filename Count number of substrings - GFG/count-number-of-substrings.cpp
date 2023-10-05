//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    long long int atleast(string &s, int k)
    {
        int n = s.size(), cnt = 0, hsh[26] = {0}, j = 0;
        long long ans = 0;
        
        for(int i = 0; i<n; ++i)
        {
            while(cnt < k && j<n) cnt += (hsh[s[j++] -'a']++==0);
            if(cnt == k) ans += 1ll*(n-j+1);
            cnt -= (--hsh[s[i]-'a'] == 0);
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	return atleast(s, k)-atleast(s, k+1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends