long long inf = LLONG_MIN;
class Seg {
private:
    int n;
    vector<long long> tree;

public:
    Seg(int n) {
        this->n = n;
        tree.resize(4 * n, inf);
    }
    long long query(int node, int st, int end, int l, int r) {
        if (l > r)
            return inf;
        if (st == l && end == r)
            return tree[node];
        int mid = (st + end) / 2;
        return max(query(2 * node + 1, st, mid, l, min(r, mid)),
                   query(2 * node + 2, mid + 1, end, max(l, mid + 1), r));
    }
    void update(int node, int st, int end, int idx, long long val) {
        if (st == end && st == idx) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (st + end) / 2;
        if (idx <= mid)
            update(2 * node + 1, st, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        vector<int> unique;
        for (auto it : st)
            unique.push_back(it);
        int n = nums.size(), m = unique.size();
        long long ans = inf;
        // dp[i][0] -> greater, dp[i][1] -> smaller
        vector<vector<long long>> dp(n, vector<long long>(2, inf));
        Seg up(m), down(m);

        auto getIdx = [&](int x) {
            return lower_bound(unique.begin(), unique.end(), x) -
                   unique.begin();
        };

        for (int i = 0; i < n; ++i) {
            if (i - k >= 0) {
                int j = i - k;
                int jid = getIdx(nums[j]);
                up.update(0, 0, m - 1, jid, dp[j][0]);
                down.update(0, 0, m - 1, jid, dp[j][1]);
            }
            dp[i][0] = dp[i][1] = nums[i];
            int idx = getIdx(nums[i]);

            long long bestDown = down.query(0, 0, m - 1, 0, idx - 1);
            if (bestDown != inf)
                dp[i][0] = max(dp[i][0], nums[i] + bestDown);

            long long bestUp = up.query(0, 0, m - 1, idx + 1, m - 1);
            if (bestUp != inf)
                dp[i][1] = max(dp[i][1], nums[i] + bestUp);
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};