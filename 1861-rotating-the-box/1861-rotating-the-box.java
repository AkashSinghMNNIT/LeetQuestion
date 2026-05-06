class Solution {
    public char[][] rotateTheBox(char[][] grid) {
        char[][] boxGrid = Arrays.stream(grid).map(row -> row.clone()).toArray(char[][]::new);
        int m = boxGrid.length, n = boxGrid[0].length;
        for(int i = 0; i<m; ++i){
            for(int j = n-1, k = n-1; j>=0; --j){
                if(boxGrid[i][j] == '*') k = j;
                if(boxGrid[i][j]!='.'){
                    char temp = boxGrid[i][j];
                    boxGrid[i][j] = boxGrid[i][k];
                    boxGrid[i][k] = temp;
                    --k;
                }
            }
        }
        char[][] ans = new char[n][m];
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                ans[j][m-i-1] = boxGrid[i][j];
            }
        }
        return ans;
    }
}