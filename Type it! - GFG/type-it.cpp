//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int n = s.length();
        if(n == 0) return 0;
        if(n&1) return 1 + minOperation(s.substr(0, n-1));
        else 
        {
            int ans = n;
            for(int i = 0; i<=n; i+=2)
            {
                string a = s.substr(0, (n-i)/2), b = s.substr((n-i)/2, (n-i)/2);
                if(a==b) ans = min(ans, 1 + i + (n-i)/2);
            }
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends