class Solution {
    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        List<Integer> prevAlice = new ArrayList<>();
        List<Integer> prevBob = new ArrayList<>();

        int pre[] = new int[n + 1];
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + stones[i];

        // Base case (rem = 2)
        for (int i = 0; i < n - 1; ++i) {
            prevAlice.add(Math.max(stones[i], stones[i + 1]));
            prevBob.add(-Math.max(stones[i], stones[i + 1]));
        }

        // DP Transitions
        for (int rem = 3; rem <= n; ++rem) {
            List<Integer> currAlice = new ArrayList<>();
            List<Integer> currBob = new ArrayList<>();
            for (int i = 0; i + rem - 1 < n; ++i) {
                // Alice options
                int takeFirst = pre[i + rem] - pre[i + 1] + prevBob.get(i + 1);
                int takeLast = pre[i + rem - 1] - pre[i] + prevBob.get(i);
                currAlice.add(Math.max(takeFirst, takeLast));

                // Bob options
                takeFirst = -(pre[i + rem] - pre[i + 1]) + prevAlice.get(i + 1);
                takeLast = -(pre[i + rem - 1] - pre[i]) + prevAlice.get(i);
                currBob.add(Math.min(takeFirst, takeLast));
            }
            prevAlice = currAlice;
            prevBob = currBob;
        }
        return prevAlice.get(0);
    }
}