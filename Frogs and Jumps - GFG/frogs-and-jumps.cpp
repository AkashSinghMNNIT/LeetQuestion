//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        int mp[leaves+1];
        memset(mp, 0, sizeof(mp));
        for(int j = 0; j<N; ++j)
        {
            if(frogs[j]==1) return 0;
            if(frogs[j]<=leaves && mp[frogs[j]]==0)
            for(int i = frogs[j]; i<=leaves; i += frogs[j]) mp[i] = 1;
        }
        int cnt = 0;
        for(int i = 1; i<=leaves; ++i) cnt += !mp[i];
        return cnt;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends