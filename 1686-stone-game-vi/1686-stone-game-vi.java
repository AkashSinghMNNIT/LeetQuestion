class Solution {
    public int stoneGameVI(int[] alice, int[] bob) {
        int n = alice.length;
        Integer[] idx = IntStream.range(0, n).boxed()
        .sorted((i, j) -> ((alice[j]+bob[j]) -(alice[i]+bob[i])))
        .toArray(Integer[]::new);

        int sum = 0;
        for(int i = 0; i<n; ++i){
            if((i&1) == 0)
                sum += alice[idx[i]];
                else sum -= bob[idx[i]];
        }
        return Integer.compare(sum, 0);
    }
}