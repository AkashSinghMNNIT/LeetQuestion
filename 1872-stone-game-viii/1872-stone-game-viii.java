class Solution {
    public int stoneGameVIII(int[] stones) {
        int n = stones.length;
        int[] pre = new int[n+1];

        for(int i = 0; i<n; ++i) pre[i+1] = pre[i]+stones[i];

        int[] alice = new int[n+1];
        int[] bob = new int[n+1];
        alice[n] = pre[n];
        bob[n] = -pre[n];

        for(int i = n-1; i>=2; --i){
            alice[i] = Math.max(alice[i+1], pre[i]+bob[i+1]);
            bob[i] = Math.min(bob[i+1], -pre[i]+alice[i+1]);
        }
        return alice[2];
    }
}