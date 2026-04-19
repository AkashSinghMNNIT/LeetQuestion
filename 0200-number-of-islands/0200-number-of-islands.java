class Solution {
    private int[] dir = new int[]{0, 1, 0, -1, 0};
    private boolean isvalid(int r, int c, char[][] dup){
        int n = dup.length, m = dup[0].length;
        return r>=0 && c>=0 && r<n && c<m && dup[r][c]=='1';
    }
    private void dfs(int x, int y, char[][] dup){
        dup[x][y] = '0';
        for(int i = 0; i<4; ++i){
            int r = x+dir[i], c = y+dir[i+1];
            if(isvalid(r, c, dup)) {
                dfs(r, c, dup);
            }
        }
    }
    public int numIslands(char[][] grid) {
        char[][] dup = grid;
        int n = grid.length, m = grid[0].length, ans = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(dup[i][j] == '1'){
                    ++ans;
                    dfs(i, j, dup);
                }
            }
        }
        return ans;
    }
}