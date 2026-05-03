class Solution {
    public long maximumScore(int[][] grid) {
        int n = grid.length;
        long[][] prefix = new long[n][n + 1];
        for (int col = 0; col < n; ++col) {
            for (int row = 0; row < n; ++row)
                prefix[col][row + 1] = prefix[col][row] + grid[row][col];
        }
        long[] prevpick = new long[n + 1], prevskip = new long[n + 1];

        for (int i = 1; i < n; ++i) {
            long[] currpick = new long[n + 1], currskip = new long[n + 1];
            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    if (curr > prev) {
                        long score = prefix[i - 1][curr] - prefix[i - 1][prev];
                        currpick[curr] = Math.max(currpick[curr], prevskip[prev] + score);
                        currskip[curr] = Math.max(currskip[curr], prevskip[prev] + score);
                    } else {
                        long score = prefix[i][prev] - prefix[i][curr];
                        currpick[curr] = Math.max(currpick[curr], prevpick[prev] + score);
                        currskip[curr] = Math.max(currskip[curr], prevpick[prev]);
                    }
                }
            }
            prevpick = currpick;
            prevskip = currskip;
        }
        long ans = 0;
        for(int i = 0; i<=n; ++i) ans = Math.max(ans, prevpick[i]);
        return ans;
        // return Arrays.stream(prevpick).max().orElse(0L);
    }
}