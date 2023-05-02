//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long

bool pre(vector<int> &s,ll mid, ll k)
{
    ll sum = 0, cnt = 0, n = s.size();
    for(int i = 0; i<n; ++i)
    {
        sum += s[i];
        if(sum >= mid) sum = 0, cnt++;
    }
    if(sum >= mid)++cnt;
    return cnt>k;
}

class Solution{
    public:
    int maxSweetness(vector<int>& s, int n, int k) {
        ll l = 0, h = accumulate(s.begin(), s.end(), 1ll);
        while(h-l>1)
        {
            ll mid = (h+l)/2;
            if(pre(s, mid, k)) l = mid;
            else h = mid;
        }
        return l;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends