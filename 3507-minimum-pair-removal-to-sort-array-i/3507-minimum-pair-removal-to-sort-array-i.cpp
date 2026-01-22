class Solution {
public:
    vector<int> update(vector<int> v) {
        int n = v.size(), minIdx = n - 1;
        vector<int> ans;
        for (int i = n - 1; i > 0; --i) {
            if ((v[i] + v[i - 1]) <= (v[minIdx] + v[minIdx - 1]))
                minIdx = i;
        }
        for (int i = 0; i < n; ++i) {
            if (i == minIdx) {
                int last = ans.back();
                ans.pop_back();
                ans.push_back(last + v[i]);
                continue;
            }
            ans.push_back(v[i]);
        }
        return ans;
    }
    bool isNonDecreasing(vector<int>& v) {
        int mx = -10000;
        for (auto it : v) {
            if (it < mx)
                return 0;
            mx = it;
        }
        return 1;
    }
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> v = nums;
        int cnt = 0;
        while (!isNonDecreasing(v)) {
            v = update(v);
            ++cnt;
        }
        return cnt;
    }
};