class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pre = mat;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                pre[i][j] += (i > 0 ? pre[i - 1][j] : 0) +
                             (j > 0 ? pre[i][j - 1] : 0) -
                             (i > 0 && j > 0 ? pre[i - 1][j - 1] : 0);
        }

        auto check = [&](int i, int j, int len) -> bool {
            int area = pre[i+len-1][j+len-1] - (i>0?pre[i-1][j+len-1]: 0) - (j>0?pre[i+len-1][j-1]:0) + (i>0 && j>0 ? pre[i-1][j-1]:0);
            return area <= threshold;
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int len = min(m-i, n-j); len > max(ans, 0); --len) {
                    if (check(i, j, len)) {
                        ans = max(ans, len);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};