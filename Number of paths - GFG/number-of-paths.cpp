//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long mod = 1e9+7;
    long long fact(long long m)
    {
        long long ans = 1;
        while(m) ans = (ans * m--)%mod;
        return ans;
    }
    long long bin(long long a, long long b)
    {
        long long ans = 1; 
        while(b)
        {
            if(b & 1) ans = (ans * a)%mod;
            a = (a*a)%mod;
            b >>= 1;
        }
        return ans;
    }
    long long  numberOfPaths(int m, int n)
    {
        long long ans = 1;
        for(long long i = n; i<(m+n-1); ++i) ans = (ans * i)%mod;
        return (ans * bin(fact(m-1), mod-2))%mod;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends