class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int ans = 0;
        for(auto it: times) ans += (it[0] < times[targetFriend][0]) - (it[1]<=times[targetFriend][0]);
        return ans;
    }
};