class Solution {
public:
    long long minimumSteps(string s) {
        long long n = s.length(), ans = 0, cnt = 0;
        for(auto it: s)
        {
            cnt += (it == '1');
            ans += (it == '0')*cnt;
        }
        return ans;
    }
};