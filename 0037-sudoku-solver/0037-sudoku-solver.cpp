class Solution {
public:
    bool row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
    pair<int, int> next(int i, int j) {
        if (j == 8)
            return {i + 1, 0};
        else
            return {i, j + 1};
    }
    bool isValid(int i, int j, int num) {
        int boxNum = i - i % 3 + j/3;
        if (row[i][num] || col[j][num] || box[boxNum][num])
            return 0;
        return 1;
    }
    bool solve(int i, int j, vector<vector<char>>& board) {
        if (board[i][j] == '.') {
            for (int num = 0; num < 9; ++num) {
                if (isValid(i, j, num)) {
                    if (i < 8 || j < 8) {
                        auto[x, y] = next(i, j);
                        int boxNum = i - i % 3 + j/3;
                        board[i][j] = '1' + num;
                        row[i][num] = col[j][num] = box[boxNum][num] = 1;
                        if (solve(x, y, board))
                            return 1;
                        else
                            board[i][j] = '.',
                            row[i][num] = col[j][num] = box[boxNum][num] = 0;
                    } else {
                        board[i][j] = '1' + num;
                        return 1;
                    }
                }
            }
        } else {
            if (i < 8 || j < 8) {
                auto[x, y] = next(i, j);
                return solve(x, y, board);
            } else
                return 1;
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int boxNum = (i/3)*3 + j/3, num = board[i][j] - '1';
                    row[i][num] = col[j][num] = box[boxNum][num] = 1;
                }
            }
        }
        solve(0, 0, board);
    }
};