class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(begin(candies), end(candies)), n = size(candies);
        vector<bool> ans(n);
        for(int i = 0; i<n; ++i) ans[i] = (candies[i]+extraCandies>=mx);
        return ans;
    }
};