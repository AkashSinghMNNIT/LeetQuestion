class Solution {
    private long[][][] ans = new long[17][10][2];
    private boolean[] onPath = new boolean[16];
    private String s;
    private long dp(int i, int l, int t){
        if(i>=16) return 1;
        if(ans[i][l][t]!=-1) return ans[i][l][t];
        long lim = t>0?s.charAt(i)-'0':9, res = 0;
        for(int c = 0; c<=lim; ++c){
            if(onPath[i])
            {
                if(c>=l){
                    res += dp(i+1, c, c==lim?t:0);
                }
            }
            else{
                res += dp(i+1, l, c==lim?t:0);
            }
        }
        return ans[i][l][t]= res;
    }
    private long f(long n)
    {
        if(n<0) return 0;
        s = String.format("%016d", n);
        for(int i = 0; i<=16; ++i){
            for(int v = 0; v<=9; ++v)
            {
                Arrays.fill(ans[i][v], -1);
            }
        }
        return dp(0, 0, 1);
    }
    public long countGoodIntegersOnPath(long l, long r, String directions) {
        int i = 0;
        Arrays.fill(onPath, false);
        onPath[0] = true;
        for(char d: directions.toCharArray()){
            i += d=='D'?4:1;
            onPath[i] = true;
        }
        return f(r)-f(l-1);
    }
}