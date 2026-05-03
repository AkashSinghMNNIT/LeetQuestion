class Solution {
    private int[] computeLPS(char[] goal) {
        int n = goal.length;
        int[] lps = new int[n];
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && goal[i] != goal[j])
                j = lps[j - 1];
            if (goal[i] == goal[j])
                lps[i] = ++j;
        }
        return lps;
    }

    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length())
            return false;
        int n = goal.length();
        int[] lps;
        char[] text = (s + s).toCharArray();
        char[] pattern = goal.toCharArray();

        lps = computeLPS(pattern);

        for (int i = 0, j = 0; i < 2 * n; ++i) {
            while (j > 0 && text[i] != pattern[j])
                j = lps[j - 1];
            if (text[i] == pattern[j])
                ++j;
            if (j == n)
                return true;
        }
        return false;

    }
}