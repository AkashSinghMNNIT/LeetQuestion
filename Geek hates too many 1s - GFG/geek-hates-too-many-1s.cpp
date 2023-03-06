//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        int x = log2(n)+1;
        for(int i = x; i>1; --i)
        {
            if((n & (1<<i)) && (n & (1<<(i-1))) && (n & (1<<(i-2))) ) n ^= (1<<(i-2));
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends