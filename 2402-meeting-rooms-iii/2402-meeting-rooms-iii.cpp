class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long,int>>> used;
        priority_queue<int, vector<int>, greater<int>> unused;
        for(int i = 0; i<n; ++i) unused.push(i);
        vector<int> ans(n, 0);
        sort(meet.begin(), meet.end());
        for(int i = 0; i<meet.size(); ++i)
        {
            int start = meet[i][0], end = meet[i][1];
            while(!used.empty() && used.top().first <= start)
            {
                unused.push(used.top().second);
                used.pop();
            }
            if(!unused.empty())
            {
                ++ans[unused.top()];
                used.push({end, unused.top()});
                unused.pop();
            }
            else 
            {
                ++ans[used.top().second];
                used.push({end + used.top().first-start, used.top().second});
                used.pop();
            }
        }
        int min = 0;
        for(int i = 0; i<n; ++i) 
            if(ans[min] < ans[i]) min = i;
       
        return min;
    }
};