class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;
        for(auto it: arr) mp[(it%k + k)%k]++;
        for(int i = 0; i<k; ++i) if(mp[i] != mp[(k-i)%k] || (i==(k-i)%k && (mp[i]&1))) return 0;
        return 1;
    }
};