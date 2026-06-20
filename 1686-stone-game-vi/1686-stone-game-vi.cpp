class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n = alice.size();
        priority_queue<pair<int, int>> q;
        for(int i = 0; i<n; ++i){
            q.push({alice[i]+bob[i], i});
        }
        int sum = 0;
        for(int i = 0; i<n; ++i){
            auto top = q.top();
            q.pop();
            if(i&1) sum -= bob[top.second];
            else sum += alice[top.second];
        }
        if(sum)
        sum /= abs(sum);
        return sum;
    }
};