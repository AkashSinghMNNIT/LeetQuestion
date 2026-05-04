class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                matrix[i][j] = matrix[i][j] ^ matrix[n - j - 1][n - i - 1];
                matrix[n - j - 1][n - i - 1] = matrix[i][j] ^ matrix[n - j - 1][n - i - 1];
                matrix[i][j] = matrix[i][j] ^ matrix[n - j - 1][n - i - 1];
            }
        }
        
        for (int col = 0; col <n; ++col) {
            for (int row = 0; row < n/2; ++row) {
                matrix[row][col] = matrix[row][col] ^ matrix[n-row-1][col];
                matrix[n-row-1][col] = matrix[row][col] ^ matrix[n-row-1][col];
                matrix[row][col] = matrix[row][col] ^ matrix[n-row-1][col];
            }
        }

    }
}