class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        for(auto it: arr) mp[it]++;
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto [f, s]: mp) q.push(s);
        while(k>0)
        {
            int top = q.top();
            q.pop();
            if(top > k) q.push(top-k);
            k -= min(top, k);
        }
        return q.size();
    }
};