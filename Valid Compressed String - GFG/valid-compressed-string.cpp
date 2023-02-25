//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0, num = 0;
        for(int i = 0; i<m; ++i)
        {
            if(t[i]>='0' && t[i]<='9')
            {
                num *= 10;
                num += t[i]-'0';
            }
            else
            {
                if(j+num >= n) return 0;
                else j += num, num = 0;
                if(s[j] != t[i]) return 0;
                ++j;
            }
        }
        if(j+num != n) return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends