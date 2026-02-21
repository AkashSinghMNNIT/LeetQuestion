class Solution {
    private int countbit(int n) {
        int ans = 0;
        while (n > 0) {
            n = (n ^ (n & -n));
            ++ans;
        }
        return ans;
    }

    public int countPrimeSetBits(int left, int right) {
        int ans = 0;
        Set<Integer> st = Set.of(2, 3, 5, 7, 11, 13, 17, 19 );
        for (int i = left; i <= right; ++i) {
            if (st.contains(countbit(i))) {
                ++ans;
            }
        }
        return ans;
    }
}