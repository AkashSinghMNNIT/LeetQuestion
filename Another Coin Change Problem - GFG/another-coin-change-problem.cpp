//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool makeChanges(int n, int k, int tar, vector<int> &coins) {
        vector<vector<bool>> dp(k+1, vector<bool> (tar+1, 0));
        dp[0][0] = 1;
        for(int noc = 1; noc <= k; ++noc) // noc -> number of coin
        {
            for(int sum = 1; sum<=tar; ++sum)
            {
                for(auto it: coins)
                {
                    if(sum-it >= 0 && dp[noc-1][sum-it]) 
                    {
                        dp[noc][sum] = 1;
                        break;
                    }
                }
            }
        }
        return dp[k][tar];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends