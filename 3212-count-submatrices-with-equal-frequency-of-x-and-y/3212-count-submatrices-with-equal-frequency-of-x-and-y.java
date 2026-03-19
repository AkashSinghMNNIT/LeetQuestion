class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int n = grid.length, m = grid[0].length, ans = 0;
        int [][][]cnt = new int[n][m][2];
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                cnt[i][j][0] = (grid[i][j]=='X'?1:0)+(i>0?cnt[i-1][j][0]:0)+(j>0?cnt[i][j-1][0]:0) - (i>0 && j>0? cnt[i-1][j-1][0]:0);
                cnt[i][j][1] = (grid[i][j]=='Y'?1:0)+(i>0?cnt[i-1][j][1]:0)+(j>0?cnt[i][j-1][1]:0) - (i>0 && j>0? cnt[i-1][j-1][1]:0);
                if(cnt[i][j][0]>0 && cnt[i][j][0]==cnt[i][j][1]) ++ans;
            }
        }
        return ans;
    }
}