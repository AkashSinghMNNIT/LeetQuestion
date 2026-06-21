class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};
        for(auto it: stones) cnt[it%3]++;
        if(cnt[0] & 1){
            return abs(cnt[1]-cnt[2])>2;
        }
        else return cnt[1] && cnt[2];
    }
};