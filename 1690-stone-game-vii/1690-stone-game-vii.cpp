class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prev[2]; // 0 -> alice score, 1 -> bob score
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + stones[i];
        for (int i = 0; i < n - 1; ++i) {
            prev[0].push_back(max(stones[i], stones[i + 1]));
            prev[1].push_back(min(-stones[i], -stones[i + 1]));
        }
        for (int rem = 3; rem <= n; ++rem) {
            vector<int> curr[2];
            for (int i = 0; i + rem - 1 < n; ++i) {
                curr[0].push_back(
                    max(pre[i + rem] - pre[i + 1] + prev[1][i + 1],
                        pre[i + rem - 1] - pre[i] + prev[1][i]));
                curr[1].push_back(
                    min(-(pre[i + rem] - pre[i + 1]) + prev[0][i + 1],
                        -(pre[i + rem - 1] - pre[i]) + prev[0][i]));
            }
            prev[0] = curr[0], prev[1] = curr[1];
        }
        return prev[0][0];
    }
};