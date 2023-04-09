//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
ll inf = 1e9+7;
bool check(ll num, ll a, ll b)
{
    while(num)
    {
        int rem = num % 10;
        if(rem == a || rem == b) return 1;
        num /= 10;
    }
    return 0;
}

ll bin(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1) ans = (ans * a) %inf;
        a = (a* a)%inf;
        b >>= 1;
    }
    return ans;
}

class Solution {
  public:
    int bestNumbers(int n, int a, int b, int c, int d) {
        if(a == b) 
        {
            if(check(a * n, c, d)) return 1;
            return 0;
        }
        
        ll fact[n+2];
        fact[0] = 1;
        for(int i = 1; i<=n; ++i) fact[i] = (i*fact[i-1])%inf;
        ll ans = 0;
        for(int i = 0; i<=n; ++i)
        {
            
            if(check(a*i + b*(n-i), c, d)) ans += (fact[n] * ((bin(fact[i], inf-2) * bin(fact[n-i], inf-2))%inf))%inf;
            ans %= inf;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends