class Solution {
    public int numberOfSpecialChars(String word) {
        int[] place = Arrays.stream(new int[26]).map(i -> -1).toArray();
        int n = word.length(), ans = 0;
        char[] w = word.toCharArray();
        for (int i = 0; i < n; ++i) {
            if (w[i] >= 'A' && w[i] <= 'Z' && place[w[i] - 'A'] == -1)
                place[w[i] - 'A'] = i;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (w[i] >= 'a' && w[i] <= 'z') {
                if (place[w[i] - 'a'] > i)
                    ++ans;
                place[w[i] - 'a'] = -1;
            }
        }
        return ans;
    }
}