class Solution {
    private int mod = 1000000007;

    private int dfs(int i, int evilmatch, boolean lb, boolean rb, String s1, String s2, int[] lps, String evil, int[] dp) {
        int n = s1.length(), m = evil.length();
        if (evilmatch == m)
            return 0;
        if (i == n)
            return 1;
        int key = getKey(i, evilmatch, lb, rb);
        if(dp[key]!=-1) return dp[key];
        char from = lb ? s1.charAt(i) : 'a';
        char to = rb ? s2.charAt(i) : 'z';
        int ans = 0;
        for (char c = from; c <= to; ++c) {
            int j = evilmatch;
            while (j > 0 && evil.charAt(j) != c)
                j = lps[j - 1];
            if (evil.charAt(j) == c)
                ++j;
            ans = (ans + dfs(i + 1, j, lb && (c == from), rb && (c == to), s1, s2, lps, evil, dp)) % mod;
        }
        return dp[key] = ans;
    }

    private int getKey(int i, int match, boolean lb, boolean rb) {
        return (i << 8) | (match << 2) | ((lb ? 1 : 0) << 1) | (rb ? 1 : 0);
    }

    private int[] computeLPS(String evil) {
        int n = evil.length();
        int[] lps = new int[n];
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && evil.charAt(i) != evil.charAt(j))
                j = lps[j - 1];
            if (evil.charAt(i) == evil.charAt(j))
                lps[i] = ++j;
        }
        return lps;
    }

    public int findGoodStrings(int n, String s1, String s2, String evil) {
        int[] dp = new int[(1<<17)];
        Arrays.fill(dp, -1);
        return dfs(0, 0, true, true, s1, s2, computeLPS(evil), evil, dp);
    }
}