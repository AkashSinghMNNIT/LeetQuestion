class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre(n+1, 0);
        for(int i = 0; i<n; ++i) pre[i+1] = pre[i] + stones[i];
        vector<int> alice(n+1, 0), bob(n+1, 0);
        alice[n] = pre[n], bob[n] = -pre[n];
        for(int i = n-1; i>=2; --i){
            alice[i] = max(alice[i+1], pre[i]+bob[i+1]);
            bob[i] = min(bob[i+1], -pre[i]+alice[i+1]);
        }
        return alice[2];
    }
};