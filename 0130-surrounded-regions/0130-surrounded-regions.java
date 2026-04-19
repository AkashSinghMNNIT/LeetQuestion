class Solution {
    private int[] dir = new int[]{0, 1, 0, -1, 0};
    private boolean isvalid(int x, int y, char[][] grid){
        int m = grid.length, n = grid[0].length;
        return x>=0 && y>=0 && x<m && y<n && grid[x][y]=='O';
    }
    private void dfs(int x, int y, Set<String> st, char[][] grid){
        if(st.contains(x+","+y)) return;
        st.add(x+","+y);
        for(int i = 0; i<4; ++i){
            int r = x+dir[i], c = y+dir[i+1];
            if(isvalid(r, c, grid)) dfs(r, c, st, grid);
        }
    }
    public void solve(char[][] board) {
        Set<String> st = new HashSet<>();
        int m = board.length, n = board[0].length;
        for(int i = 0; i<m; ++i){
            if(board[i][0]=='O') dfs(i, 0, st, board);
            if(board[i][n-1]=='O') dfs(i, n-1, st, board);
        }
        for(int i = 0; i<n; ++i){
            if(board[0][i]=='O') dfs(0, i, st, board);
            if(board[m-1][i]=='O') dfs(m-1, i, st, board);
        }
        for(int i = 1; i<m-1; ++i){
            for(int j = 1; j<n-1; ++j)
            {
                if(board[i][j]=='O' && !st.contains(i+","+j)) board[i][j] = 'X';
            }
        }
    }
}